class Solution {
public:
    int helper(vector<int>&dp,vector<int>&nums,int ind){
        if(ind>=nums.size()){
            return 1e8;
        }
        if(ind==nums.size()-1){
            return 0;
        }
        if(nums[ind]==0){
            return 1e8;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int mini=INT_MAX;
        for(int i=1;i<=nums[ind];i++){
           int val=1+helper(dp,nums,ind+i);   
            mini=min(mini,val);  
        }
        return dp[ind]=mini;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return helper(dp,nums,0);
    }
};