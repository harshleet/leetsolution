class Solution {
    public:
    vector<vector<vector<int>>> dp;
    int helper(int m, int ind2, vector<int>& piles, int st1, int st2, int t) {
        int n=piles.size();
        if (ind2>=n) {
            return 0;
        }
       if(dp[m][ind2][t]!=-1){
           return dp[m][ind2][t];
       }
        
        if (t == 1) {
            int result=0;
            int stone=0;
            for(int i=1;i<=2*m && ind2+i-1<n ;i++){
                stone+=piles[ind2+i-1];
               result=max(result,stone+helper(max(i,m), ind2+i, piles, st1 + stone, st2, 0));
            }
            return dp[m][ind2][t]= result;
            
        } int result=INT_MAX;
         int stone=0;
            for(int i=1;i<=2*m && ind2+i-1<n;i++){
                   stone+=piles[ind2+i-1];
               result=min(result,helper(max(i,m), ind2+i, piles, st1 , st2+stone, 1));
            }
            return dp[m][ind2][t]= result;
      
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
       dp.resize(n + 1, vector<vector<int>>(n, vector<int>(2, -1)));
        return helper(1, 0, piles, 0, 0, 1);
    }
};