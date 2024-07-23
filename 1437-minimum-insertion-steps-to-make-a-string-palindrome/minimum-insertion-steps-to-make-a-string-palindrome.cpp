class Solution {
public:
    int minInsertions(string s) {
        string t=s;
        reverse(s.begin(),s.end());
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1));
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                int nt=max(dp[i][j-1],dp[i-1][j]);
                int ta=0;
                if(s[i-1]==t[j-1]){
                    ta=1+dp[i-1][j-1];
                }
                dp[i][j]=max(ta,nt);
            }
        }
        return s.size()-dp[s.size()][t.size()];
    }
};