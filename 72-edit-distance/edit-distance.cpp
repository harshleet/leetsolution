class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));

        for(int i=0;i<=word1.size();i++){
            dp[i][0]=i;
        }

        for(int i=0;i<=word2.size();i++){
            dp[0][i]=i;
        }
        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                int in=1+dp[i][j-1];
                int de=1+dp[i-1][j];
                int re=1+dp[i-1][j-1];
                int t=1e9;
                if(word1[i-1]==word2[j-1]){
                    t=dp[i-1][j-1];
                }
               dp[i][j]=min({in,de,re,t});
            }
        }
        return dp[word1.size()][word2.size()];
    }
};