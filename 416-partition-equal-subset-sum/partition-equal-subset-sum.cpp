class Solution {
public:
bool helper(int ind,int subsum,vector<int>&arr,int k,int n,vector<vector<int>>&dp){
    if(ind>=n){
        if(subsum==k){
            return true;
        }
        return false;
    }
  
    if(dp[ind][subsum]!=-1){
        return dp[ind][subsum];
    }
   

    bool ntake=helper(ind+1,subsum,arr,k,n,dp);
    bool take=false;
    if (subsum+arr[ind] <= k) {
        take=helper(ind + 1, subsum + arr[ind], arr, k, n, dp);
    }
    return dp[ind][subsum]=take|ntake;
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0){
            return false;
        }
        int k=sum/2;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
       return helper(0,0,nums,k,n,dp);
    }
};