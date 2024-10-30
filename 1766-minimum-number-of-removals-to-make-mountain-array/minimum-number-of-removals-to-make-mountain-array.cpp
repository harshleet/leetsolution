class Solution {
public:
    int helper(int ind,int pre,int pri,int n,vector<int>&nums,vector<vector<vector<int>>>&dp){
        if(ind>=n){
            if(pri==1){
                return 0;
            }
            return -1e9;
        }

        if(dp[ind][pre+1][pri]!=-1){
            return dp[ind][pre+1][pri];
        }
        int nt=helper(ind+1,pre,pri,n,nums,dp);
        int t1=0,t2=0;
        if(pre==-1){
            t1=1+helper(ind+1,ind,pri,n,nums,dp);
            
        }else if(pri==0 && nums[pre]<nums[ind]){
            t1=1+helper(ind+1,ind,pri,n,nums,dp);
            t2=1+helper(ind+1,ind,1,n,nums,dp);
        }else if(pri==1 &&  nums[pre]>nums[ind]){
            t2=1+helper(ind+1,ind,pri,n,nums,dp);
        }
        return dp[ind][pre+1][pri]=max({nt,t1,t2});
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n,1);
        vector<int>dp2(n,1);

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]< nums[i] && dp1[j]+1>dp1[i]){
                    dp1[i]=1+dp1[j];
                }
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[j]< nums[i] && dp2[j]+1>dp2[i]){
                    dp2[i]=1+dp2[j];
                }
            }
        }

        int maxi=0;
        for(int i=0;i<n;i++){
            if(dp1[i]>=2 && dp2[i]>=2){
            maxi=max(maxi,dp1[i]+dp2[i]);}
        }
        return n-maxi+1;
    }
};