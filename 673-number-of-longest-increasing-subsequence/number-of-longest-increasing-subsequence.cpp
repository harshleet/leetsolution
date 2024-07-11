class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
         int n=nums.size();
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
         int lis=0;
        for(int i=0; i<n; i++){
            for(int pre = 0; pre<i; pre++){
                if(nums[pre]<nums[i] && dp[i]<1+dp[pre]){
                    dp[i]=1 + dp[pre];
                    cnt[i]=cnt[pre];
                }else if(nums[pre]<nums[i] && dp[i]==1+dp[pre]){
                    cnt[i]+=cnt[pre];
                }
            }
            lis=max(lis,dp[i]);
        }
        int ans=0;
        for(int i=0;i<cnt.size();i++){
            if(dp[i]==lis){
                ans+=cnt[i];
            }
            // cout<<it<<" ";
        }
        return ans;
    }
};