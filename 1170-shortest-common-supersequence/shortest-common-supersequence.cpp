class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = n, j = m;
        string ans = "";
        while (i >= 1 && j >= 1) {
            if (str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        reverse(ans.begin(), ans.end());
       
       i = 0, j = 0;
       int k = 0;
       string a="";
        while (i < str1.size() && j < str2.size() && k < ans.size()) {
             if(str1[i]!=ans[k]){
                a+=str1[i];
                i++;
            }if(str2[j]!=ans[k]){
                a+=str2[j];
                j++;
            } if(str1[i]==str2[j] && str2[j]==ans[k]){
                a+=str1[i];
                i++;
                j++;
                k++;
            }
        }
        cout<<a<<" ";
         while(i<str1.size()){
            a+=str1[i];
            i++;
        }
        while(j<str2.size()){
            a+=str2[j];
            j++;
        }
        // while(k<ans.size()){
        //     a+=ans[i];
        //     k++;
        // }
        return a;
    }
};