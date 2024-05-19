class Solution {
public:
    int helper(int ind1,int ind2,string word1,string word2,int n,int m,vector<vector<int>>&dp){
        if(ind1>=n ){
            return word2.size()-ind2 ;
        }
        if(ind2>=m ){
            return word1.size()-ind1 ;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        int nop=INT_MAX;
        if(word1[ind1]==word2[ind2]){
            nop=helper(ind1+1,ind2+1,word1,word2,n,m,dp);
        }
        int re=1+helper(ind1+1,ind2+1,word1,word2,n,m,dp);
        int de=1+helper(ind1+1,ind2,word1,word2,n,m,dp);
        int in=1+helper(ind1,ind2+1,word1,word2,n,m,dp);
        return dp[ind1][ind2]= min({re,de,in,nop});
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,word1,word2,n,m,dp);
    }
};