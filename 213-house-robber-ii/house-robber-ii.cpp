class Solution {
public:
 int helper(int ind,vector<int>&nums,int n,vector<vector<int>>&dp,int ftaken){
        if(ind>=n){
            return 0;
        }
        if(dp[ind][ftaken]!=-1){
            return dp[ind][ftaken];
        }
        int ntake=helper(ind+1,nums,n,dp,ftaken);
        int take=INT_MIN;
        
            if(ind==0){
                   take=nums[ind]+helper(ind+2,nums,n,dp,1);
            }else if(ind==n-1 && ftaken==0){
                take=nums[ind]+helper(ind+2,nums,n,dp,ftaken);
            }else if(ind!=0 && ind!=n-1){
                take=nums[ind]+helper(ind+2,nums,n,dp,ftaken);
            }
  
        return dp[ind][ftaken]=max(ntake,take);
    }
    int rob(vector<int>& nums) {
         int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
         return helper(0,nums,n,dp,0);
    }
};