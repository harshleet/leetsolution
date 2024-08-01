class Solution {
public:
   int helper(int ind,int pswap,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>&dp){
    if(ind>=nums1.size()){
        return 0;
    }
    if(dp[ind][pswap]!=-1){
        return dp[ind][pswap];
    }
    int nop=INT_MAX,op=INT_MAX;
      if(ind==0){
        nop=helper(ind+1,pswap,nums1,nums2,dp);
        op=1+helper(ind+1,1,nums1,nums2,dp);
      }else if(pswap==0){
        if(nums1[ind]>nums1[ind-1] && nums2[ind]>nums2[ind-1]){
            nop=helper(ind+1,0,nums1,nums2,dp);
            if(nums2[ind]>nums1[ind-1] && nums1[ind]>nums2[ind-1]){
                op=1+helper(ind+1,1,nums1,nums2,dp);
            }
        }else if(nums2[ind]>nums1[ind-1] && nums1[ind]>nums2[ind-1]){
             op=1+helper(ind+1,1,nums1,nums2,dp);
        }
      }else if(pswap==1){
        if(nums1[ind]>nums2[ind-1] && nums2[ind]>nums1[ind-1]){
            nop=helper(ind+1,0,nums1,nums2,dp);
            if(nums2[ind]>nums2[ind-1] && nums1[ind]>nums1[ind-1]){
                op=1+helper(ind+1,1,nums1,nums2,dp);
            }
        }else if(nums2[ind]>nums2[ind-1] && nums1[ind]>nums1[ind-1]){
             op=1+helper(ind+1,1,nums1,nums2,dp);
        }
      }
      return dp[ind][pswap]=min(nop,op);
   }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(),vector<int>(2,-1));
        return helper(0,0,nums1,nums2,dp);
        
    }
};