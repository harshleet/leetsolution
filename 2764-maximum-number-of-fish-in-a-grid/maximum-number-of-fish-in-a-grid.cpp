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
        }else if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else if(rank[ulp_v]==rank[ulp_u]){
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
      
    }
};

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        DisjointSet ds(n*m);
        vector<int>fish(n*m,0);
        vector<int>dr={1,-1,0,0};
        vector<int>dc={0,0,-1,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                fish[i*m+j]=grid[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    for(int k=0;k<4;k++){
                        int nr=i+dr[k];
                        int nc=j+dc[k];
                        if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]>0){
                            if(ds.findUPar(m*i+j)!=ds.findUPar(nr*m+nc)){
                                int p1=ds.findUPar(m*i+j);
                                int p2=ds.findUPar(nr*m+nc);
                                ds.unionByRank(p1,p2);
                                fish[ds.findUPar(nr*m+nc)]=fish[p1]+fish[p2];
                            }
                        }
                    }
                }
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ds.findUPar(i*m+j)==i*m+j){
                    maxi=max(maxi,fish[i*m+j]);
                }
            }
        }
        return maxi;
    }
};