class Solution {
public:
    bool isPal(string &s,int st,int en){
       while(st<=en){
        if(s[st]!=s[en]){
            return false;
        }
        st++;
        en--;
       }
        return true;
    }
    int helper(int i,string &s,vector<int>&dp){
        if(i>=s.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }  
        int mini=INT_MAX;
        for(int k=1;k<=s.size()-i;k++){
           
            if( isPal(s,i,i+k-1)){
                mini=min(mini,1+helper(i+k,s,dp));
            }

        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        //s.size()^3
        vector<int>dp(s.size(),-1);
        return helper(0,s,dp)-1;
    }
};