class Solution {
public:
int helper(vector<pair<int,int>>&v,vector<vector<int>>&dp,int ind,int preage){
    if(ind>=v.size()){
        return 0;
    }
    if(dp[ind][preage]!=-1){
        return dp[ind][preage];
    }
    int ntake=helper(v,dp,ind+1,preage);
    int take=0;
    if(v[ind].second>=preage){
        take+=v[ind].first+helper(v,dp,ind+1,v[ind].second);
    }
    return dp[ind][preage]=max(take,ntake);
}
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
          int n=scores.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({scores[i],ages[i]});
        }
        sort(v.begin(),v.end());
      
       vector<vector<int>>dp(n,vector<int>(1001,-1));
       return helper(v,dp,0,0);
    }
};