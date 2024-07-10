class Solution {
public:
    bool helper(int i,int j,string& s,string& p,vector<vector<int>>&dp,int n,int m){
        if(i==n && j==m){
            return true;
        }
        if(i==n){
            for(int k=j;k<p.size();k++){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(j==m){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(p[j]=='*'){
            return dp[i][j]=helper(i,j+1,s,p,dp,n,m)|helper(i+1,j,s,p,dp,n,m);
        }else if(p[j]=='?'){
           return dp[i][j]=helper(i+1,j+1,s,p,dp,n,m);
        }else if(s[i]==p[j]){
            return dp[i][j]=helper(i+1,j+1,s,p,dp,n,m);
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size(),vector<int>(p.size(),-1));
       
        return helper(0,0,s,p,dp,s.size(),p.size());
    }
};