class Solution {
public:
   int helper(int ind,int size,vector<int>& arr, int k,int maxi,vector<vector<int>>&dp){
       if(ind>=arr.size()){
        
           return 0;
       }

       if(dp[ind][size]!=-1){
           return dp[ind][size];
       }
       int end=max(maxi,arr[ind])*(size+1)+helper(ind+1,0,arr,k,INT_MIN,dp);
       int cont=INT_MIN;
       if(size<k-1){
             cont=helper(ind+1,size+1,arr,k,max(maxi,arr[ind]),dp);
       }
       return dp[ind][size]=max(end,cont);
   }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<vector<int>>dp(arr.size(),vector<int>(k,-1));
        return helper(0,0,arr,k,INT_MIN,dp);
    }
};