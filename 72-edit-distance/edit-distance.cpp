class Solution {
public:
    
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,1e9));
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=i;
        }
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                    int ins=1+dp[ind1][ind2-1];
                    int del=1+dp[ind1-1][ind2];
                    int rep=1+dp[ind1-1][ind2-1];
                    int same=1e9;
                    if(word1[ind1-1]==word2[ind2-1]){
                        same=dp[ind1-1][ind2-1];
                    }
                   dp[ind1][ind2]=min({ins,del,rep,same});
            }
        }
        return dp[n][m];
    }
};