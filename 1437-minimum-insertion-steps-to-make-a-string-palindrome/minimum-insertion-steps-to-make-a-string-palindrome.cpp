class Solution {
public:
    int helper(int ind1,int ind2,string &s1,string &s2,vector<vector<int>>&dp,int n){
        if(ind1>=n ||ind2>=n){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        int in1=helper(ind1+1,ind2,s1,s2,dp,n);
        int in2=helper(ind1,ind2+1,s1,s2,dp,n);
        int nin=0;
        if(s1[ind1]==s2[ind2]){
            nin=1+helper(ind1+1,ind2+1,s1,s2,dp,n);
        }
        return dp[ind1][ind2]=max({in1,in2,nin});
    }
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        string s1=s;
        reverse(s.begin(),s.end());
        return n-helper(0,0,s1,s,dp,n);
    }
};