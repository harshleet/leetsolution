class Solution {
public:
   void helper(int k,int j,vector<vector<int>>&dp,string& s){
       if(j==k){
           dp[k][j]=1;
           return;
       }
      if(j-k==1){
          if(s[k]==s[j]){
              dp[k][j]=1;
              return;
          }else{
              dp[k][j]=0;
              return;
          }
      }
      if(s[k]==s[j] && dp[k+1][j-1]==1){
           dp[k][j]=1;
           return;
      }else{
              dp[k][j]=0;
              return;
      }
   }
    string longestPalindrome(string s) {
        if(s.size()==1){
            return s;
        }
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),0));
        int maxi=0;
        string maxst="";
        string temp="";
        for(int i=0;i<s.length();i++){
             for(int j=i,k=0;j<s.length();j++,k++){
                 helper(k,j,dp,s);
                 if(dp[k][j]==1){
                     if(maxi<j-k+1){
                        temp=s.substr(k,j-k+1);
                        maxi=max(maxi,j-k+1);
                        maxst=temp;
                     }
                 }
             }

        }
        return maxst;
    }
};