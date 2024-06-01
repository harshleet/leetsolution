class DisjointSet{
    public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
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
     void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
      
        DisjointSet ds(n*m);
        vector<int>dr={1,-1,0,0};
        vector<int>dc={0,0,1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                     for(int k=0;k<4;k++){
                        int nr=i+dr[k];
                        int nc=j+dc[k];
                        if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc] ){
                            int p1=ds.findUPar(i*m+j);
                            int p2=ds.findUPar(nr*m+nc);
                            // cout<<p1<<" "<<p2<<endl;
                            if(p1!=p2){
                                ds.unionBySize(p1,p2);
                            }
                        }
                     }
                }
            }
        }
         int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    set<int>st;
                    for(int k=0;k<4;k++){
                        int nr=i+dr[k];
                        int nc=j+dc[k];
                        if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc] ){
                            int p=ds.findUPar(nr*m+nc);
                            st.insert(p);

                        }
                    }
                    int ans=1;
                    for(auto it:st){
                         ans+=ds.size[it];
                    }
                    maxi=max(maxi,ans);
                }
            }
        }
        for(int i=0;i<n*m;i++){
            maxi=max(maxi,ds.size[i]);
        }
        return maxi;
    }
};