class Solution {
public:
    int helper(int ind1,int ind2,int n,int m,vector<vector<int>>&dp,string& word1,string& word2){
        if(ind1==n && ind2==m){
            return 0;
        }
        if(ind1>=n){
            return m-ind2;
        }
        if(ind2>=m){
            return n-ind1;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        int ins=1+helper(ind1,ind2+1,n,m,dp,word1,word2);
        int del=1+helper(ind1+1,ind2,n,m,dp,word1,word2);
        int rep=1+helper(ind1+1,ind2+1,n,m,dp,word1,word2);
        int same=1e9;
        if(word1[ind1]==word2[ind2]){
            same=helper(ind1+1,ind2+1,n,m,dp,word1,word2);
        }
        return dp[ind1][ind2]=min({ins,del,rep,same});
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,n,m,dp,word1,word2);
    }
};