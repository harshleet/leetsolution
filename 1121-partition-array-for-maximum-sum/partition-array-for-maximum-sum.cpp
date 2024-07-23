class Solution {
public:
    int helper(int ind,vector<int>&arr,int k,vector<int>&dp){
        if(ind>=arr.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int maxi=0;
        int ans=0;
        for(int i=ind;i<min(ind+k,int(arr.size()));i++){
            maxi=max(maxi,arr[i]);
            ans=max(ans,maxi*(i-ind+1)+helper(i+1,arr,k,dp));
        }
        return dp[ind]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       vector<int>dp(arr.size(),-1);
        return helper(0,arr,k,dp);
    }
};