class Solution {
public:
    
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                
            }
        }
        int i=n,j=m;
        string ans="";
        while(i>=1 && j>=1){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;
                j--;
            }else if(dp[i][j-1]>dp[i-1][j]){
                 ans+=str2[j-1];
                j--;
            }else{
                 ans+=str1[i-1];
                i--;
            }
        }
        while(i>=1){
            ans+=str1[i-1];
                i--;
        }
        while(j>=1){
            ans+=str2[j-1];
                j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};