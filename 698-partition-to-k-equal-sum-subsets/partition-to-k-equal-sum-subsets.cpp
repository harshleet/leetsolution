class Solution {
public:
bool helper(int count,int bitmask,int sum,int target,int n,vector<int>&nums,int& bitm,  vector<vector<int>>& dp){
    if(bitmask==bitm){
        return count==n;
    }
   if(dp[count][bitmask]!=-1){
       return  dp[count][bitmask];
   }
    bool re=false;
    for(int i=0;i<nums.size();i++){
        if(sum+nums[i]<=target && !((1<<i)&bitmask)){
            if(sum+nums[i]==target){
                re=helper(count+1,bitmask^(1<<i),0,target,n,nums,bitm,dp);
                 if(re==true){
            break;
        }
            }else{
                re=helper(count,bitmask^(1<<i),sum+nums[i],target,n,nums,bitm,dp);
                 if(re==true){
            break;
        }
            }
        }
       
    }
    return dp[count][bitmask]=re;
}
    bool canPartitionKSubsets(vector<int>& nums, int n) {
        int N=nums.size();

        int k = accumulate(nums.begin(), nums.end(), 0);
        if (k % n != 0) {
            return false;
        }
        int target = k /n ;
        vector<vector<int>> dp(N, vector<int>(1<<N, -1));
        
      int bitm=((1<<N)-1);
      return helper(0,0,0,target,n,nums,bitm,dp);

    }
};