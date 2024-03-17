class DisjointSet{
    vector<int>parent,size;
    public:
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1,0);
            for(int i=0;i<=n;i++){
                parent[i]=i;
                size[i]=1;
            }
        }

        int findUPar(int node){
            if(node==parent[node]){
                return node;
            }
            return parent[node]=findUPar(parent[node]);
        }
        void unionBySize(int u,int v){
            int uPar=findUPar(u);
            int vPar=findUPar(v);
            if(size[uPar]<=size[vPar]){
                parent[uPar]=vPar;
                size[vPar]+=size[uPar];
            }else{
                 parent[vPar]=uPar;
                size[uPar]+=size[vPar];
            }
        }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cnt=0;
        int ncon=connections.size();
        for(int i=0;i<ncon;i++){
            if(ds.findUPar(connections[i][0])!=ds.findUPar(connections[i][1])){
                 ds.unionBySize(connections[i][0],connections[i][1]);
            }else{
                cnt++;
            }
        }
        
        int rep=cnt;
        int cn=ncon-rep+1;
        int ncn=n-cn;
        if(ncn>rep){
            return -1;
        }
        return ncn;

    }
};