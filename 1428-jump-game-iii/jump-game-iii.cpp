class Solution {
public:
    bool helper(int ind,vector<int>&arr,vector<int>&dp){
        if(arr[ind]==0){
            return true;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        bool ans=false;
        dp[ind]=ans;
        if(ind-arr[ind]>=0){
            ans=ans||helper(ind-arr[ind],arr,dp);
        }

        if(ind+arr[ind]<arr.size()){
            ans=ans||helper(ind+arr[ind],arr,dp);
        }
        return dp[ind]=ans;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>dp(arr.size(),-1);
        return helper(start,arr,dp);
    }
};