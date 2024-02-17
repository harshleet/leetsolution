class Solution {
public:
vector<int>d={1,7,30};
    int helper(int ind,int last,vector<int>&days,vector<int>&costs, vector<vector<int>>&dp){
        if(ind>=days.size()){
            return 0;
        }
        if(dp[ind][last+1]!=-1){
            return dp[ind][last+1];
        }
         int mini=1e8;
        if(last>=days[ind]){
            mini=min(mini,helper(ind+1,last,days,costs,dp));    
        }
       
        for(int i=0;i<3;i++){
           mini=min(mini,costs[i]+helper(ind+1,days[ind]+d[i]-1,days,costs,dp));
        }
        return dp[ind][last+1]=mini;

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        sort(days.begin(),days.end());
        vector<vector<int>>dp(days.size(),vector<int>(days.back()+31,-1));
        return helper(0,-1,days,costs,dp);
    }
};