class Solution {
public:
void helper(string s,set<string> &word,int start,vector<int>&dp,vector<string>&ans,string ds){
        if(start == s.size()){
            ans.push_back(ds);
            return;
        } 
       
      for(int i=start;i<s.size();i++){
          string left=s.substr(start,i+1-start);
          if(word.find(left)!=word.end() ){
              string temp=ds;
              if(ds!=""){
                  ds+=" ";
              }
              ds+=left;   
              helper(s,word,i+1,dp,ans,ds);
              ds=temp;
          }
      }
   
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
         set<string>word(wordDict.begin(),wordDict.end());
       vector<int>dp(s.size(),-1);
       vector<string>ans;
       string ds="";
     helper(s,word,0,dp,ans,ds);
      return ans;
    }
};