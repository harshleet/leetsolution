class Solution {
public:
    int helper(int ind,map<int,int>&m,vector<int>& nums,vector<int>&dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int nd=helper(ind+1,m,nums,dp);
        int d=0;
        if(m[nums[ind]]>0){
            int a= m[nums[ind]-1],b=m[nums[ind]+1];
            int i=upper_bound(nums.begin(),nums.end(),nums[ind]+1)-nums.begin();
             m[nums[ind]-1]=0;
             m[nums[ind]+1]=0;
            d=m[nums[ind]]*nums[ind]+helper(i,m,nums,dp);
            m[nums[ind]+1]=b;
            m[nums[ind]-1]=a;
         
        }
        return dp[ind]=max(nd,d);
        
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int>dp(nums.size(),-1);
        return helper(0,m,nums,dp);
    }
};