class Solution {
public:
   
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
    temp.push_back(nums[0]);

    int len = 1;
    vector<int>dp(n,1);
    dp[0]=1;
    vector<int>cnt(n,1);
    for (int i = 1; i < n; i++) {
       
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i] && dp[j]+1>dp[i]){
                dp[i]=1+dp[j];
                cnt[i]=cnt[j];
            }else if(nums[j]<nums[i] && dp[j]+1==dp[i]){
                cnt[i]+=cnt[j];
            }
        }
        len=max(len,dp[i]);
        // cout<<cnt[i]<<" ";
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(dp[i]==len){
            ans+=cnt[i];
        }
    }
    return ans;
    }
};