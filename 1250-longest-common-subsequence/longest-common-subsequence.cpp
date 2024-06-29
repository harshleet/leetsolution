class Solution {
public:
    int helper(int ind1,int ind2,string text1,string text2,int n,int m){
        if(ind1>=n || ind2>=m){
            return 0;
        }
        int nt1=helper(ind1+1,ind2,text1,text2,n,m);
        int nt2=helper(ind1,ind2+1,text1,text2,n,m);
        int t=0;
        if(text1[ind1]==text2[ind2]){
            t=1+helper(ind1+1,ind2+1,text1,text2,n,m);
        }
        return max({nt1,nt2,t});
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int nt1=dp[i-1][j];
                int nt2=dp[i][j-1];
                int t=0;
                if(text1[i-1]==text2[j-1]){
                    t=1+dp[i-1][j-1];
                }
                dp[i][j]= max({nt1,nt2,t});
            }
        }
        return dp[n][m];
    }
};