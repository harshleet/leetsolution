class Solution {
public:
   bool helper(string s,set<string> &word,int start,vector<int>&dp){
        if(start == s.size()){
            return true;
        } 
        if(dp[start]!=-1){
            return dp[start];
        }
      for(int i=start;i<s.size();i++){
          string left=s.substr(start,i+1-start);
          
          if(word.find(left)!=word.end() && helper(s,word,i+1,dp)){
              return dp[start]= true;
          }
      }
      return dp[start]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>word(wordDict.begin(),wordDict.end());
       vector<int>dp(s.size(),-1);
      
       return  helper(s,word,0,dp);
     
       
    }
};