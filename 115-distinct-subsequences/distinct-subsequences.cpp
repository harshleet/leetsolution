class Solution {
public:
    int helper(int ind1,int ind2,string& s,string& t,vector<vector<int>>&dp,int n,int m){
        if(ind2>=m){
            return 1;
        }
        if(ind1>=n){
            return 0;
        }
          if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
          }
        int op1=helper(ind1+1,ind2,s,t,dp,n,m);
        int op2=0;
        if(s[ind1]==t[ind2]){
            op2=helper(ind1+1,ind2+1,s,t,dp,n,m);
        }
        return dp[ind1][ind2]=op1+op2;
    }
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,s,t,dp,n,m);
    }
};