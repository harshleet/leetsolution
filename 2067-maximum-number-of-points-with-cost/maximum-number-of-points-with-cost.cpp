class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int m=points[0].size();
        vector<vector<long long>>dp(n,vector<long long>(m,-1));
        for(int i=0;i<m;i++){
            dp[0][i]=points[0][i];
        }

        for(int r=1;r<n;r++){
            vector<long long>left(m),right(m);
            left[0]=dp[r-1][0]+0;

            for(int c=1;c<m;c++){
                left[c]=max(left[c-1],dp[r-1][c]+c);
               
            }
            right[m-1]=dp[r-1][m-1]-m+1;
            for(int c=m-2;c>=0;c--){
                right[c]=max(right[c+1],dp[r-1][c]-c);
               
            }

            for(int c=0;c<m;c++){
                dp[r][c]=points[r][c]+max(left[c]-c,right[c]+c);
            }
        }
        return *max_element(dp[n-1].begin(),dp[n-1].end());
    }
};