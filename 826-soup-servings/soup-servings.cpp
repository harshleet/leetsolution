class Solution {
public:
    double helper(vector<vector<double>>&dp,int sa,int sb,vector<vector<int>>&types){
        if( sa<=0 && sb<=0){
            return 0.5;
        }
        if(sa<=0){
            return 1.0;
        }
        if(sa>=0 && sb<=0){
            return 0.0;
        }
        
        if(dp[sa][sb]!=-1.0){
            return dp[sa][sb];
        }
        double ans=0.0;

        for(int i=0;i<4;i++){
           
               ans+=helper(dp,sa-types[i][0],sb-types[i][1],types);
        }
        return dp[sa][sb]=ans*0.25;
    }
    double soupServings(int n) {
        //in first though looks of dp can take hint from  khight probability problem
        int max=n/25;
       if(n>10000) return 1;
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1.0));
        vector<vector<int>>types={{100,0},{75,25},{50,50},{25,75}};
       double val= helper(dp,n,n,types);
        return val;
    }
};