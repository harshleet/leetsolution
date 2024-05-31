class DisjointSet{
    vector<int>parent,rank;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);

        if(ulp_u==ulp_v){
            return;
        }
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }else if(rank[ulp_v]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else if(rank[ulp_v]==rank[ulp_u]){
            parent[ulp_v]=ulp_u;
            rank[ulp_v]++;
        }
      
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int ans=0,to=0;
        for(auto it:connections){
            if(ds.findUPar(it[0])!=ds.findUPar(it[1])){
                ds.unionByRank(it[0],it[1]);
                to++;
            }else{
                ans++;
            }
        }
        cout<<to<<" "<<ans<<" "<<n-1<<endl;
        if(n-1==to){
            return 0;
        }
        if(ans+to<n-1){
            return -1;
        }
        return n-1-to;
    }
};