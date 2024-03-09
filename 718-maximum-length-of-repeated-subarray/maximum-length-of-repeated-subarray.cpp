class Solution {
public:
int ans=0;
int helper(int ind1,int ind2,vector<int>& nums1,vector<int>& nums2,vector<vector<int>>&dp,int cnt){
    if(ind1>=nums1.size() || ind2>=nums2.size()){
        return 0;
    }
    if(dp[ind1][ind2]!=-1){
        return dp[ind1][ind2];
    }
    int ntake=max(helper(ind1+1,ind2,nums1,nums2,dp,0),helper(ind1,ind2+1,nums1,nums2,dp,0));
    int take=0;
    if(nums1[ind1]==nums2[ind2]){
        take=1+helper(ind1+1, ind2+1, nums1, nums2, dp,cnt+1);
    }
     ans=max(ans,take);
    

    return dp[ind1][ind2]=take;
    
}
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size(),l2=nums2.size(),l3=min(l1,l2);
        vector<vector<int>>dp(l1,vector<int>(l2,-1));
      helper(0,0,nums1,nums2,dp,0);
      return ans;
    }
};
