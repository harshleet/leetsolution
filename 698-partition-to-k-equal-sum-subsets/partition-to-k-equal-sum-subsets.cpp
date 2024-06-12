class Solution {
public:
   bool helper(int cnt,int sum,int bitmask,vector<int>&nums,int k,int tsum,vector<vector<int>>&dp){
        if(cnt==k && bitmask==(1<<nums.size())-1){
            return true;
        }
        if(dp[bitmask][cnt]!=-1){
            return dp[bitmask][cnt];
        }
        bool ans=false;
        for(int i=0;i<nums.size();i++){
            
            if((bitmask&(1<<(nums.size()-i-1)))==0 && nums[i]+sum<=tsum){
                bitmask=(bitmask|(1<<(nums.size()-i-1)));
                if(sum+nums[i]==tsum){
                    ans=ans| helper(cnt+1,0,bitmask,nums,k,tsum,dp);
                }else{
                    ans=ans|helper(cnt,sum+nums[i],bitmask,nums,k,tsum,dp);
                }
                bitmask=(bitmask&~(1<<(nums.size()-i-1)));
            }
        }
        return dp[bitmask][cnt]=ans;

   }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //this si reursive code
        //now to amke use of dp

        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0){
            return false;
        }
        int n=nums.size();
        vector<vector<int>>dp(1<<n,vector<int>(k,-1));
        return helper(0,0,0,nums,k,sum/k,dp);
    }
};