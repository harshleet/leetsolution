class Solution {
public:
  int helper(int ind,int o,int z,vector<string>& strs, int m, int n,map<int,int>&m1,map<int,int>&m2,vector<vector<vector<int>>>&dp){
    if(ind>=strs.size()){
      return 0;
    }
    if(dp[ind][o][z]!=-1){
        return dp[ind][o][z];
    }
    int ntake=helper(ind+1,o,z,strs,m,n,m1,m2,dp);
    int take=-1e9;
    if(o+m1[ind]<=n && z+m2[ind]<=m){
        take=1+helper(ind+1,o+m1[ind],z+m2[ind],strs,m,n,m1,m2,dp);
    }  
    return dp[ind][o][z]=max(take,ntake);
  }
    int findMaxForm(vector<string>& strs, int m, int n) {
        map<int,int>m1;
        map<int,int>m2;
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='1'){
                    m1[i]++;
                }else{
                      m2[i]++;
                }
            }
        }
        vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(n+1,vector<int>(m+1,-1)));
        return helper(0,0,0,strs,m,n,m1,m2,dp);
    }
};