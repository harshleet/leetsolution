class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            adj[i][i]=0;
        }
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]][edges[i][1]]=edges[i][2];
            adj[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    adj[j][k]=min(adj[j][k],adj[j][i]+adj[i][k]);
                }
            }
        }
        int mini=INT_MAX,city=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i!=j && adj[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=mini){
                mini=cnt;
                city=i;
            }
        }
        return city;
    }
};