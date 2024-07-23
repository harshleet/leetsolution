class Solution {
public:
    int helper(int ind1,int ind2,string& s,string& p,int n,int m,vector<vector<int>>&dp){
      if(ind1==n && ind2==m){
        return true;
      }   
       if(ind1==n ){
         for(int i=ind2;i<p.size();i++){
                if(p[i]!='*'){
                    return false;
                }
            }
            return true;
      } 
      if(ind2==m){
        return false;
      }
      if(dp[ind1][ind2]!=-1){
        return dp[ind1][ind2];
      }
      bool ans=false;
      if(s[ind1]==p[ind2]||p[ind2]=='?'){
        ans=ans|helper(ind1+1,ind2+1,s,p,n,m,dp);
      }else if(p[ind2]=='*'){
        for(int i=0;i<=n-ind1;i++){
            ans=ans|helper(ind1+i,ind2+1,s,p,n,m,dp);
        }
      }
      return dp[ind1][ind2]=ans;
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        if(s.size()==0){
            for(int i=0;i<p.size();i++){
                if(p[i]!='*'){
                    return false;
                }
            }
            return true;
        }
        return helper(0,0,s,p,n,m,dp);

    }
};