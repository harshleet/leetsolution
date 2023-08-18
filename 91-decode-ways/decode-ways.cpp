class Solution {
public:
int helper(string&s,vector<int>&dp,int ind,map<string,char>&m){
    if(ind==s.size()){
        return 1;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int take=0;

    if(m.find(s.substr(ind,1))!=m.end()){
        take+=helper(s,dp,ind+1,m);
    }
    
     if(ind + 1 < s.size() && m.find(s.substr(ind,2))!=m.end()){
        take+=helper(s,dp,ind+2,m);
    }
  
    return dp[ind]=take;
}
    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);
        map<string,char>m;
        for(int i=1;i<=26;i++){
            string a=to_string(i);
           m[a]='A'+i-1;
        }

       return  helper(s,dp,0,m);
    }
};