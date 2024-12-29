class Solution {
public:
    int mod=1e9+7;
    int helper(int ind,int cind,vector<vector<int>>&dp,vector<vector<int>>&temp,string &target){
        if(cind>=target.size()){
            return 1;
        }
        if(ind>=temp.size()){
            return 0;
        }
        if(dp[ind][cind]!=-1){
            return dp[ind][cind];
        }

        long long nt=helper(ind+1,cind,dp,temp,target);
        long long t=0;
        if(temp[ind][int(target[cind]-'a')]!=0){
                t = (1LL * temp[ind][int(target[cind] - 'a')] * helper(ind + 1, cind + 1, dp, temp, target)) % mod;  
                      }
        return dp[ind][cind]=(nt+t)%mod;
    }
    int numWays(vector<string>& words, string target) {

        vector<vector<int>>temp(1001,vector<int>(26,0));
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                temp[j][int(words[i][j]-'a')]++;
            }
        }
        vector<vector<int>>dp(1001,vector<int>(1001,-1));
        return helper(0,0,dp,temp,target);
    }
};