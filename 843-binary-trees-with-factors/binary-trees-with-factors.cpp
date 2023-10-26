class Solution {
public:
int mod=1e9+7;
    int helper(int ind,vector<int>& arr,vector<int>&dp){
        if(ind>=arr.size()){
            return 0;
        }
       if(dp[ind]!=-1){
           return dp[ind];
       }
        int ans=1;
        for(int i=ind+1;i<arr.size();i++){
            if((arr[ind]%arr[i]==0)&&find(arr.begin(), arr.end(),arr[ind]/arr[i])!=arr.end()){
                int val=find(arr.begin(), arr.end(),arr[ind]/arr[i])-arr.begin();
                if(arr[ind]%arr[val]==0 ){
                    long long l=helper(i,arr,dp);
                    long long r=helper(val,arr,dp);
                  ans=(ans+(l*r)%mod)%mod;
                }
            }
        }
    
        return dp[ind]=ans;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        vector<int>dp(arr.size(),-1);
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
         int a=0;
         for(int i=0;i<arr.size();i++){
             a=(a+(helper(i,arr,dp))%mod)%mod;
         }
        return a;
    }
};