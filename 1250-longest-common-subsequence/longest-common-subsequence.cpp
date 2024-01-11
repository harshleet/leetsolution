class Solution {
public:
    int f(string& s1,string& s2,int i,int j,vector<vector<int>>&dp){
           if(i<0 || j<0){
               return 0;
           }
           if(dp[i][j]!=-1){
               return dp[i][j];
           }
           int ntake=max(f(s1,s2,i-1,j,dp),f(s1,s2,i,j-1,dp));
           int take=0;
           if(s1[i]==s2[j]){
               take=1+f(s1,s2,i-1,j-1,dp);
           }
           return dp[i][j]=max(ntake,take);

    }
   
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
        return f(text1,text2,text1.length()-1,text2.length()-1,dp);
        
    }
};