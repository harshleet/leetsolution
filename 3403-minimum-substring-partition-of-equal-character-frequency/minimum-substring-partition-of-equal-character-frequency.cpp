class Solution {
public:
    int helper(int ind, string s, int n, vector<int>& dp) {
        if (ind >= n) {
            return 0;
        }
         if(dp[ind]!=-1){
            return dp[ind];
         }
        int p = INT_MAX;
        vector<int> temp(26, 0);
        for (int i = ind; i < n; i++) {
            temp[s[i] - 'a']++;
  
            int mini = INT_MAX;
            int maxi = 0;
   
            for (int j = 0; j < 26; j++) {
                if (temp[j] != 0) {
                    mini = min(mini, temp[j]);
                    maxi = max(maxi, temp[j]);
                }
            }
            
            if(maxi==mini){
                p=min(p,1+helper(i+1,s,n,dp));
            }
        }
        return  dp[ind]=p;
    }
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
       
        
        return helper(0, s, n, dp);
    }
};