class Solution {
public:
    int helper(int st,int end,int len,vector<int>&cut,vector<vector<int>>&dp){
        if(st>end){
            return 0;
        }
        if(dp[st][end]!=-1){
            return dp[st][end];
        }
         int mini=1e8;
        for(int i=st;i<=end;i++){
            
                int c=(cut[end+1]-cut[st-1])+helper(st,i-1,len,cut,dp)+helper(i+1,end,len,cut,dp);
                mini=min(mini,c);
    
        }
        
        return dp[st][end]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
       
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
         vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1));
        return helper(1,cuts.size()-2,n,cuts,dp);
    }
};