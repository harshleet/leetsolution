class Solution {
public:
    int helper(int state,int ind,vector<vector<int>>&dp,vector<int>&nums){
        if(ind==nums.size()){
            return 0;
        }
        if(dp[ind][state]!=-1){
            return dp[ind][state];
        }
        int take=INT_MAX,ntake=INT_MAX,changes=INT_MAX;
        for(int i=1;i<4;i++){
            if(i!=nums[ind]){
                if(i>=state){
                    take=min(take,1+helper(i,ind+1,dp,nums));
                }
            }
        }//try all four options u get
        if(nums[ind]>=state){
            ntake=0+helper(nums[ind],ind+1,dp,nums);
           
        }
        return dp[ind][state]= min(take,ntake);
    }
    int minimumOperations(vector<int>& nums) {
   
        vector<vector<int>>dp(nums.size(),vector<int>(4,-1));
        return helper(0,0,dp,nums);
        
    }
};