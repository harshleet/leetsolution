class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        vector<int>cnt(nums.size(),1);

        int maxi=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    cnt[i]=cnt[j];
                }else if(nums[j]<nums[i] && 1+dp[j]==dp[i]){
                    cnt[i]+=cnt[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(dp[i]==maxi){
                ans+=cnt[i];
            }
        }
        return ans;
    }
};