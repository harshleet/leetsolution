class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
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
      
        int i=n,j=m;
        string lcs="";
        while(i>=1 && j>=1){
            if(text1[i-1]==text2[j-1]){
                lcs+=text1[i-1];
                i--;
                j--;
            }else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
        reverse(lcs.begin(),lcs.end());
        i=0,j=0;
        int k=0;
        string ans="";
        while(i<n && j<m && k<lcs.size()){
            if(text1[i]==lcs[k] && text2[j]==lcs[k] ){
                ans+=text1[i];
                i++;
                j++;
                k++;
            }if(text1[i]!=lcs[k]){
                ans+=text1[i];
                i++;
            }if(text2[j]!=lcs[k]){
                ans+=text2[j];
                j++;
            }
        }
        while(i<n){
            ans+=text1[i];
            i++;
        }
        while(j<m){
            ans+=text2[j];
            j++;
        }
        return ans;
    }
};