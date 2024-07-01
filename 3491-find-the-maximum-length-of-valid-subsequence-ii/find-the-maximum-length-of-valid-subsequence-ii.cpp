class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>>dp(k,vector<int>(k,0));
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            int curr=nums[i]%k;
            for(int prev=0;prev<k;prev++){
                dp[curr][prev]=max(dp[curr][prev],1+dp[prev][curr]);
                maxi=max(maxi,dp[curr][prev]);
            }
        }
        return maxi;
    }
};