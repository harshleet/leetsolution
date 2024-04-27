class Solution {
public:
    int helper(int ind,int prev,string ring,string key,int si,vector<vector<int>>&dp){
        if(ind>=key.size()){
            return 0;
        }
        if(dp[ind][prev]!=-1){
            return dp[ind][prev];
        }
        int c=INT_MAX;
        for(int i=0;i<ring.size();i++){
            if(key[ind]==ring[i]){
                    c=min(c,1+((si+prev-i)%si)+helper(ind+1,i,ring,key,si,dp));
                    c=min(c,1+((si+i-prev)%si)+helper(ind+1,i,ring,key,si,dp));   
            }
        }
        return dp[ind][prev]=c;
    }
    int findRotateSteps(string ring, string key) {
        int n=ring.size();
        vector<vector<int>>dp(key.size(),vector<int>(n,-1));
        return helper(0,0,ring ,key,ring.size(),dp);
    }
};