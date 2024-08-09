class Solution {
public:
    int helper(int ind,int pre,vector<vector<int>>&tot,vector<vector<int>>&dp){
        if(ind>=tot.size()){
            return 0;
        }
        if(dp[ind][pre+1]!=-1){
            return dp[ind][pre+1];
        }
        int nt=helper(ind+1,pre,tot,dp);
        int t=0;
        if(pre==-1|| tot[pre][0]==tot[ind][0] || tot[pre][1]<=tot[ind][1]){
            t=tot[ind][1]+helper(ind+1,ind,tot,dp);
        }
        return dp[ind][pre+1]=max(t,nt);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>>tot(scores.size());
        for(int i=0;i<scores.size();i++){
            tot[i]={ages[i],scores[i]};
        }
        sort(tot.begin(),tot.end());
        vector<vector<int>>dp(scores.size(),vector<int>(scores.size(),-1));
        return helper(0,-1,tot,dp);
    }
};