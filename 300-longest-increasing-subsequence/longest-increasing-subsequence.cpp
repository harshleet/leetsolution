class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(nums.size(),1);
        int gmax=1;
        for(int ind=1;ind<n;ind++){
            int maxi=1;
            for(int pre=ind-1;pre>=0;pre--){
                
                 if(nums[ind]>nums[pre]){
                    maxi=max(maxi,1+dp[pre]);
                }
                dp[ind]=maxi;
                gmax=max(gmax,dp[ind]);
            }
        }
        return gmax;
       
    }
};