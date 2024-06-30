class Solution {
public:
  class DisjointSet {
    vector<int> rank, Parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        Parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            Parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == Parent[node])
            return node; 
        return Parent[node] = findUPar(Parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            Parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            Parent[ulp_v] = ulp_u; 
        }
        else {
            Parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            Parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            Parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end());
        reverse(edges.begin(),edges.end());
        DisjointSet ds1(n);
        DisjointSet ds2(n);
        set<vector<int>>extra;
        for(auto it:edges){
            if((it[0]==1 || it[0]==3 )&&ds1.findUPar(it[1])!=ds1.findUPar(it[2])){
                ds1.unionBySize(ds1.findUPar(it[1]),ds1.findUPar(it[2]));
            }else if(it[0]==1 || it[0]==3 ){
                extra.insert(it);
            }
        }
        int pare=-1;
        for(int i=1;i<=n;i++){
            if(pare!=-1 && ds1.findUPar(i)!=pare){
                return -1;
            }
            pare=ds1.findUPar(i);
        }
        set<vector<int>>extra2;
        for(auto it:edges){
            if((it[0]==2 || it[0]==3) && ds2.findUPar(it[1])!=ds2.findUPar(it[2])){
                ds2.unionBySize(ds2.findUPar(it[1]),ds2.findUPar(it[2]));
            }else if(it[0]==2 || it[0]==3 ){
                extra2.insert(it);
            }
        }
        pare=-1;
        for(int i=1;i<=n;i++){
            if(pare!=-1 && ds2.findUPar(i)!=pare){
                return -1;
            }
            pare=ds2.findUPar(i);
        }
        int cn=0;
        for(auto it:extra){
            // cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
            if(extra2.find(it)!=extra2.end()){
                cn++;
            }else if(it[0]==1){
                cn++;
            }
        } 
        for(auto it:extra2){
            // cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
            if(it[0]==2){
                cn++;
            }
        } 
        return cn;
    }
};