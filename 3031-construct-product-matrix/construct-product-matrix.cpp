class Solution {
public:
int mod=12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        long long int p=1,s=1;
        vector<vector<long long int>>pre(grid.size(),vector<long long int>(grid[0].size()));
        vector<vector<long long int>>suf(grid.size(),vector<long long int>(grid[0].size()));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
               pre[i][j]=p;
               suf[grid.size()-1-i][grid[0].size()-1-j]=s;
               s=(s*grid[grid.size()-1-i][grid[0].size()-1-j])%mod;
               p=(p*grid[i][j])%mod;
            }
        }
          vector<vector<int>>ans(grid.size(),vector<int>(grid[0].size()));
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
               ans[i][j]=(pre[i][j]*suf[i][j])%mod;
            }
        }
        return ans;

    }
};