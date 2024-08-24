class Solution {
public:
    class DisjointSet{
        vector<int>rank;
        vector<int>par;
        public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            par.resize(n+1);
            for(int i=0;i<=n;i++){
                par[i]=i;
            }
        }

        int findUPar(int node){
            if(node==par[node]){
                return node;
            }
            return par[node]=findUPar(par[node]);
        }

        void unionByRank(int u,int v){
            int upar=findUPar(u);
            int vpar=findUPar(v);

            if(upar==vpar){
                return;
            }
            if (rank[upar] > rank[vpar]) {
                par[vpar] = upar;
            } else if (rank[upar] < rank[vpar]) {
                par[upar] = vpar;
            } else {
                par[upar] = vpar;
                rank[vpar]++;
            }
        }
    };
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet ds1(n);
        DisjointSet ds2(n);

        int c=0;
        vector<vector<int>>maybe;
        for(int i=0;i<edges.size();i++){
            int t=edges[i][0],n1=edges[i][1],n2=edges[i][2];
            if(t==3){
                if(ds1.findUPar(n1)==ds1.findUPar(n2) && ds2.findUPar(n1)==ds2.findUPar(n2)){
                    c++;
                }
                ds1.unionByRank(n1,n2);
                ds2.unionByRank(n1,n2);
            }
        }

        for(int i=0;i<edges.size();i++){
            int t=edges[i][0],n1=edges[i][1],n2=edges[i][2];
            if(t==1){
                if(ds1.findUPar(n1)==ds1.findUPar(n2)){
                    c++;
                }
                ds1.unionByRank(n1,n2);
                // ds2.unionByRank(n1,n2);
            }
            if(t==2){
                 if(ds2.findUPar(n1)==ds2.findUPar(n2)){
                    c++;
                }
                // ds1.unionByRank(n1,n2);
                ds2.unionByRank(n1,n2);
            }
        }
        int a=0,b=0;
        for(int i=1;i<=n;i++){
            // cout<<i<<" "<<ds1.findUPar(i)<<" "<<ds2.findUPar(i)<<endl;
            if(ds1.findUPar(i)==i){
                a++;
            }
            if(ds2.findUPar(i)==i){
                b++;
            }
        }
        if(a!=1 || b!=1){
            return -1;
        }
        return c;
    }
};