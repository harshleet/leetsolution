class Solution {
public:
    bool helper(int ind1,int ind2,string &s,string &p,vector<vector<int>>&dp){
        if(ind1==s.size() && ind2==p.size()){
            return true;
        }
        if(ind1>=s.size()){
            for(int i=ind2;i<p.size();i++){
                if(p[i]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(ind2>=p.size()){
            return false;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        if(p[ind2]=='*'){
            bool a=false;
           for(int i=ind1;i<=s.size();i++){
              a|=helper(i,ind2+1,s,p,dp);
           }
           return dp[ind1][ind2]=a;
        }
        if(p[ind2]=='?'){
            return dp[ind1][ind2]=helper(ind1+1,ind2+1,s,p,dp);
        }
        if(p[ind2]!=s[ind1]){
            return dp[ind1][ind2]=false;
        }
        return dp[ind1][ind2]=helper(ind1+1,ind2+1,s,p,dp);
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size(),vector<int>(p.size(),-1));
        return helper(0,0,s,p,dp);
    }
};