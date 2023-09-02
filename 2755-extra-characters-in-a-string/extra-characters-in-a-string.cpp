class Solution {
public:
    int helper(string s,set<string> &word,int start,vector<int>&dp){
        
        if(start >= s.size()){
    
            return 0;
        } 
       
         if(dp[start]!=-1){
            return dp[start];
        }
        int ntake=1+helper(s,word,start+1,dp);
        int take=INT_MAX;
        for(int i=start;i<s.size();i++){
            string left=s.substr(start,i+1-start);
            if(word.find(left)!=word.end()){
                take=min(take,helper(s,word,i+1,dp));
            }
        }
        return dp[start]=min(take,ntake);
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string>word(dictionary.begin(),dictionary.end());
        vector<int>dp(s.size(),-1);
        return helper(s,word,0,dp);

    }
};