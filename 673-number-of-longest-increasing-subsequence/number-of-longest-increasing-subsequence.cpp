class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums.size(), 1);
        vector<int>cnt(nums.size());
        cnt[0]=1;
        int gmax = 1;
        for (int ind = 1; ind < n; ind++) {
            int maxi = 1,c=1;
            for (int pre = ind - 1; pre >= 0; pre--) {

                if (nums[ind] > nums[pre]) {
                   if(maxi<1 + dp[pre]){
                     maxi=1+dp[pre];
                     c=cnt[pre];
                   }else if(maxi==1+dp[pre]){
                    c+=cnt[pre];
                   }
                }
            }
            cnt[ind]=c;
            dp[ind] = maxi;
            gmax = max(gmax, dp[ind]);
        }
        cout<<gmax<<" ";
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if(dp[i]==gmax){
                ans+=cnt[i];
            }
        }
        return ans;
    }
};