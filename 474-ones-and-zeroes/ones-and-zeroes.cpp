class Solution {
public:
   int helper(int ind,vector<string>&strs,int m,int n,map<int,int>&on,map<int,int>&ze,vector<vector<vector<int>>>&dp){
      if(ind>=strs.size()){
        // cout<<m<<" "<<n<<endl;
        return 0;
      }  
      if(dp[ind][m][n]!=-1){
        return dp[ind][m][n];
      }
      int nt=helper(ind+1,strs,m,n,on,ze,dp);
      int t=0;
      if(m-ze[ind]>=0 && n-on[ind]>=0){
        t=1+helper(ind+1,strs,m-ze[ind],n-on[ind],on,ze,dp);
      }
      return dp[ind][m][n]=max(t,nt);
   }
    int findMaxForm(vector<string>& strs, int m, int n) {
        map<int,int>on;
        map<int,int>ze;
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='0'){
                    ze[i]++;
                }else{
                    on[i]++;
                }
            }
        }
        vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return helper(0,strs,m,n,on,ze,dp);
    }
};