class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dis(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            dis[i][i]=0;
        }
        for(auto it:edges){
            dis[it[0]][it[1]]=it[2];
            dis[it[1]][it[0]]=it[2];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(dis[j][i]+dis[i][k]<dis[j][k]){
                        dis[j][k]=dis[j][i]+dis[i][k];
                    }
                }
            }
        }
        int mini=INT_MAX,minii=-1;
         for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(i!=j && dis[i][j]<=distanceThreshold){
                    c++;
                }
            }
            cout<<c<<" ";
            if(c<=mini){
                mini=c;
                minii=i;
            }
         }
         return minii;
    }
};