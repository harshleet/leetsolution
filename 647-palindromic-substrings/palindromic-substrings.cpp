class Solution {
public:
int helper(int i,int j,vector<vector<int>>&dp,string &s){
    if(i>j){
        return 1;
    }
    if(s[i]!=s[j]){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int c=0;
    if(s[i]==s[j]){
        c+=helper(i+1,j-1,dp,s);
    }
    return dp[i][j]=c;

}
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                
                c+=helper(i,j,dp,s);
            }
        }
        return c;
    }
};