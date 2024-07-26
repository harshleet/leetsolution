class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(auto it:edges){
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if( dist[j][k]>dist[j][i]+dist[i][k] ){
                        dist[j][k]=dist[j][i]+dist[i][k];
                    }
                }
            }
        }
        int mini=INT_MAX;
        int minc=-1;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold){
                    c++;
                }
            }
            if(c<=mini){
                mini=c;
                minc=i;
            }
        }
        return minc;

    }
};