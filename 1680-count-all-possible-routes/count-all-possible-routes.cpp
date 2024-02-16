class Solution {
public:
int MOD=1e9+7;
    int helper(vector<int>& locations, int ind, int finish, int fuel,vector<vector<int>>&dp){
        if(ind==finish){
            int c=1;
             for(int i=0;i<locations.size();i++){
                int f=abs(locations[i]-locations[ind]);
                if(fuel-f>=0 && i!=ind){
                 c=(c+helper(locations,i,finish,fuel-f,dp))%MOD;
                }
                
            }
            return c;
        }
        if(dp[ind][fuel]!=-1){
            return dp[ind][fuel];
        }
        int cnt=0;
        for(int i=0;i<locations.size();i++){
            int f=abs(locations[i]-locations[ind]);
            if(fuel-f>=0 && i!=ind){
              cnt=(cnt+helper(locations,i,finish,fuel-f,dp))%MOD;
            }
            
        }
        return dp[ind][fuel]=cnt;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        vector<vector<int>>dp(n,vector<int>(fuel+1,-1));
        return helper(locations,start,finish,fuel,dp);
    }
};