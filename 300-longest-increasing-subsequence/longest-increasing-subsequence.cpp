class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int maxi=0;
        vector<int>dp(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};