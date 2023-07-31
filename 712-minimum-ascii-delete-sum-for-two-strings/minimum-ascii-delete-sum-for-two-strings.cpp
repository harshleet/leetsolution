class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
          int n = s1.size();
  int m = s2.size();

  vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i <= m; i++) {
    dp[0][i] = 0;
  }

  for (int ind1 = 1; ind1 <= n; ind1++) {
    for (int ind2 = 1; ind2 <= m; ind2++) {
      if (s1[ind1 - 1] == s2[ind2 - 1])
        dp[ind1][ind2] = s1[ind1-1] + dp[ind1 - 1][ind2 - 1];
      else
        dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
    }
  }



      int p=0;
      for(int i=0;i<n;i++){
        p+=int(s1[i]);
      }
      int q=0;
      for(int i=0;i<m;i++){
        q+=int(s2[i]);
      }
  
      return p+q-2*dp[n][m];
    }
};