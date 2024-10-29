class Solution {
public:
   int mod=1e9+7;
   int dp[200][202][202];
    int helper(int ind,int gcd1,int gcd2,vector<int>&nums){
        if(ind>=nums.size()){
            if(gcd1==gcd2 && gcd1!=-1 && gcd2!=-1){
                return 1;
            }
            return 0;
        }
        if(dp[ind][gcd1+1][gcd2+1]!=-1){
            return dp[ind][gcd1+1][gcd2+1];
        }
        int ntt=helper(ind+1,gcd1,gcd2,nums);
        int nt=0;
        if(gcd2==-1){
            nt=helper(ind+1,gcd1,nums[ind],nums);
        }else{
            nt=helper(ind+1,gcd1,__gcd(gcd2,nums[ind]),nums);
        }

        int t=0;
        if(gcd1==-1){
            t=helper(ind+1,nums[ind],gcd2,nums);
        }else{
            t=helper(ind+1,__gcd(gcd1,nums[ind]),gcd2,nums);
        }
        return dp[ind][gcd1+1][gcd2+1]=((t+nt)%mod+ntt)%mod;

    }
    int subsequencePairCount(vector<int>& nums) {
        //take -ntake 
        memset(dp, -1, sizeof(dp));
        return helper(0,-1,-1,nums);
    }
};