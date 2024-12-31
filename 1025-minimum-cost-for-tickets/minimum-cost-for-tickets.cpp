class Solution {
public:
    int helper(int day,int ind,vector<vector<int>>&dp,int maxi,vector<int>& days, vector<int>& costs){
        if(ind>=days.size()){
            return 0;
        }
        if(dp[day][ind]!=-1){
            return dp[day][ind];
        }

        int nt=1e8,od=1e8,sd=1e8,td=1e8;

        if(day>days[ind]){
            nt=helper(day,ind+1,dp,maxi,days,costs);
        }
        
        od=costs[0]+helper(days[ind]+1,ind+1,dp,maxi,days,costs);
        sd=costs[1]+helper(days[ind]+7,ind+1,dp,maxi,days,costs);
        td=costs[2]+helper(days[ind]+30,ind+1,dp,maxi,days,costs);

        return dp[day][ind]=min({od,nt,sd,td});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       sort(days.begin(),days.end());
        vector<vector<int>>dp(days.back()+32,vector<int>(days.size(),-1));

        return helper(1,0,dp,days.back(),days,costs);
    }
};