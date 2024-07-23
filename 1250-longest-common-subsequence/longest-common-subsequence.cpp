class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));

        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                int nt=max(dp[i-1][j],dp[i][j-1]);
                int t=0;
                if(text1[i-1]==text2[j-1]){
                    t=1+dp[i-1][j-1];
                }
                dp[i][j]=max(nt,t);
            }
        }
        // for(int i=text;i<=text1.size();i++){
        //     for(int j=0;j<=text2.size();j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int i=text1.size(),j=text2.size();
        string ans="";
        while(i>=1 && j>=1){
            if(text1[i-1]==text2[j-1]){
                ans+=text1[i-1];
                i--;
                j--;
            }else if(dp[i][j-1]>dp[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<" ";
        return dp[text1.size()][text2.size()];
    }
};