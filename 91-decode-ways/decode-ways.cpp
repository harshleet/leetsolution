class Solution {
public:
    int helper(int ind,string &s,vector<int>&dp,map<string,char>&m){
        if(ind==s.length()){
            return 1;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int t=0;
        if(m.find(s.substr(ind,1))!=m.end()){
            t+=helper(ind+1,s,dp,m);
        }

        if(ind<s.length()-1 && m.find(s.substr(ind,2))!=m.end() ){
            t+=helper(ind+2,s,dp,m);
        }
        return dp[ind]=t;
    }
    int numDecodings(string s) {
       map<string,char>m;
        vector<int>dp(s.length(),-1);
       for(int i=1;i<=26;i++){
           m[to_string(i)]='A'+i-1;
       }
      
       return helper(0,s,dp,m);
    }
};