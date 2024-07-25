class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]>nums[i] && dp[j]<1+dp[i]){
                    dp[j]=1+dp[i];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};