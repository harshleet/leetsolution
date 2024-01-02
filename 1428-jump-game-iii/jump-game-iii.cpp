class Solution {
public:
    bool helper(int ind,vector<int>&dp,vector<int>& arr){
        if(ind>=arr.size() || ind<0){
            return false;
        }
        if(arr[ind]==0){
            return true;
        }
        
        if(dp[ind]!=-1){
            return dp[ind];
        }
        dp[ind]=false;
        return dp[ind]=helper(ind-arr[ind],dp,arr)||helper(ind+arr[ind],dp,arr);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>dp(arr.size(),-1);
        return helper(start,dp,arr);
    }
};