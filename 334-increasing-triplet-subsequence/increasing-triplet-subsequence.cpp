class Solution {
public:
    // int f(vector<int>&nums,vector<vector<int>>&dp,int i,int pre){
    //        if(i==nums.size()){
    //            return 0;
    //        }
    //        if(dp[i][pre+1]!=-1){
    //            return dp[i][pre+1];
    //        }
    //          int ntake=f(nums,dp,i+1,pre);
    //        int take=0;
    //        if(pre==  -1 ||  nums[i]>nums[pre] ){
    //           take=1+f(nums,dp,i+1,i);
    //        }

    //        return dp[i][pre+1]=max(take,ntake);
    //     }
    bool increasingTriplet(vector<int>& nums) {
        //      vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        //    int val= f(nums,dp,0,-1);
        //    return val>=3;
        int first = INT_MAX, second = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < first) {
                first=nums[i];
            }else if(nums[i]<second && nums[i]!=first){
                second=nums[i];
            }else if(nums[i]!=first &&nums[i]!=second && first!=INT_MAX && second!=INT_MAX){
                return true;
            }
        }
        return false;
    }
};