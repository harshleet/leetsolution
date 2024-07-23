class Solution {
public:
    int numDistinct(string s, string t) {
     vector<vector<double>>dp(s.size()+1,vector<double>(t.size()+1,0));
     int n=s.size(),m=t.size();
     for(int i=0;i<=n;i++){
        dp[i][0]=1;
     }
     for(int i=1;i<=s.size();i++){
        for(int j=1;j<=t.size();j++){
            double nt=dp[i-1][j];
            double ta=0;
            if(s[i-1]==t[j-1]){
                ta=dp[i-1][j-1];
            }
            dp[i][j]=ta+nt;
        }
     }
     return int(dp[n][m]);
    }
};