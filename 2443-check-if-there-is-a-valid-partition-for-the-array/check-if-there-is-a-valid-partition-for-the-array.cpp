class Solution {
public:
    bool helper(int ind,vector<int>&nums,vector<int>&dp){
        if(ind>=nums.size()){
            return true;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        bool a=false,b=false,c=false;
        if(ind+2<nums.size() && nums[ind]==nums[ind+1] && nums[ind+1]==nums[ind+2]){
           a=helper(ind+3,nums,dp);
        }
        if(ind+1<nums.size() && nums[ind]==nums[ind+1]){
           b=helper(ind+2,nums,dp);
        }
        if(ind+2<nums.size() && nums[ind]-nums[ind+1]==-1 && nums[ind+1]-nums[ind+2]==-1){
           c=helper(ind+3,nums,dp);
        }
        return dp[ind]= a|b|c;
    }
    bool validPartition(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
       return helper(0,nums,dp);
    }
};
// class Solution {
// public:
//     bool helper(int ind,vector<int>&nums){
//         if(ind>=nums.size()){
//             return true;
//         }
//         bool a=false,b=false,c=false;
//         if(ind+2<nums.size() && nums[ind]==nums[ind+1] && nums[ind+1]==nums[ind+2]){
//            a=helper(ind+3,nums);
//         }
//         if(ind+1<nums.size() && nums[ind]==nums[ind+1]){
//            b=helper(ind+2,nums);
//         }
//         if(ind+2<nums.size() && nums[ind]-nums[ind+1]==-1 && nums[ind+1]-nums[ind+2]==-1){
//            c=helper(ind+3,nums);
//         }
//         return a|b|c;
//     }
//     bool validPartition(vector<int>& nums) {
//        return helper(0,nums);
//     }
// };