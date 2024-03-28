class Solution {
public:
    vector<int>dr1={0,0,1,1};
    vector<int>dc1={1,1,0,0};
    vector<int>dr2={0,1,0,1};
    vector<int>dc2={1,0,1,0};
  
    int helper(int row1,int col1,int row2,int col2,vector<vector<int>>&grid,int n,vector<vector<vector<vector<int>>>>&dp1){
         if(row1==n-1 && col1==n-1){
            int val=grid[row1][col1];
            // grid[row1][col1]=0;
            return val;
         }
         if(row2==n-1 && col2==n-1){
            int val=grid[row2][col2];
            // grid[row2][col2]=0;
            return val;
         }
          if(dp1[row1][col1][row2][col2]!=-1){
            return dp1[row1][col1][row2][col2];
         }
         int che=0;
         if(row1==row2 && col1==col2){
            che+=grid[row1][col1];
         }else{
            che+=grid[row1][col1]+grid[row2][col2];
         }
        //  grid[row1][col1]=0;
        // grid[row2][col2]=0;
         int maxi=INT_MIN;
         for(int i=0;i<4;i++){
            int nr1=row1+dr1[i];
            int nc1=col1+dc1[i];
            int nr2=row2+dr2[i];
            int nc2=col2+dc2[i];
            if(nr1>=0 && nc1>=0 && nr1<n && nc1<n && nr2>=0 && nc2>=0 && nr2<n && nc2<n){
                if((grid[nr1][nc1]==1|| grid[nr1][nc1]==0) && (grid[nr2][nc2]==1|| grid[nr2][nc2]==0)){
                    maxi=max(maxi,helper(nr1,nc1,nr2,nc2,grid,n,dp1));
                }
            }
         }
         return dp1[row1][col1][row2][col2]=maxi+che;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        // if(n==1){
        //     return grid[0][0]==1;
        // }
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
     
        int a= helper(0,0,0,0,grid,n,dp);
        if(a<0){
            return 0;
        }
        return a;
    }
};