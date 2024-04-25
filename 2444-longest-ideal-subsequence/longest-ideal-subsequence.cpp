class Solution {
public:
    int helper(int ind,char pre,string& s,int &k,vector<vector<int>>&dp){
        if(ind>=s.size()){
            return 0;
        }
       
        if(dp[ind][pre-'a']!=-1){
            return dp[ind][pre-'a'];
        }
        int ntake=helper(ind+1,pre,s,k,dp);
        int take=0;
        if(pre=='{'|| abs(s[ind]-pre)<=k){
            take=1+helper(ind+1,s[ind],s,k,dp);
        }
        return dp[ind][pre-'a']=max(take,ntake);
    }
    int longestIdealString(string s, int k) {
        vector<vector<int>>dp(s.size(),vector<int>(27,-1));
        return helper(0,'{',s,k,dp);
    }
};