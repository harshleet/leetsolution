class Solution {
public:

    int helper(int ind,string &s,vector<int>&dp,unordered_set<string>&st){
        if(ind>=s.size()){
            return 0;
        }
        // if(dp[ind]!=-1){
        //     return dp[ind];
        // }
        int mini=1e8;
        for(int i=1;i<=s.size()-ind;i++){
            string sub=s.substr(ind,i);
         
            if(st.find(sub)!=st.end()){
                mini=min(mini,1+helper(ind+i,s,dp,st));
            }
        }
        return dp[ind]=mini;
    }
    int minimumBeautifulSubstrings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        unordered_set<string> st{"11110100001001", "110000110101", "1001110001", "1111101", "11001", "101", "1"};
       int a =helper(0,s,dp,st);
       if(a==1e8){
          return -1;
       }
       return a;
    }
};