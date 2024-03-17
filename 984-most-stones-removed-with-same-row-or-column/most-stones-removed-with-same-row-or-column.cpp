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
    int dfs(int ind,vector<vector<int>>& stones,vector<int>&vis,int n){
        vis[ind]=1;
        int cnt=1;
        for(int i=0;i<n;i++){
           if(!vis[i] && (stones[ind][0]==stones[i][0]|| stones[i][1]==stones[ind][1])){
            cnt+=dfs(i,stones,vis,n);
           }
        }
        return cnt;
    }
    int removeStones(vector<vector<int>>& stones) {
       int n=stones.size();
       vector<int>vis(n,0);
       int cnt=0;
       for(int i=0;i<n;i++){
        if(!vis[i]){
            cnt+=dfs(i,stones,vis,n)-1;
        }
       }
       return cnt;
    }
};