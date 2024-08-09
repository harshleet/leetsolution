class Solution {
public:
    int helper(int ind, int fl,int cnt, vector<int>& temp, vector<vector<vector<int>>>& dp, int sz) {
        if (ind == sz) {
            return cnt;
        }

        if(dp[ind][fl][cnt]!=-1){
            return dp[ind][fl][cnt];
        }
        int ans = 0;
        int lim=temp[ind];
        if(fl==1){
            lim=9;
        }
        for(int i=0;i<=lim;i++){
            int updcnt = cnt;
            if (i == 1) {
                updcnt++;
            }
            if(fl==0 && i<lim){
              
                    ans+=helper(ind+1,1,updcnt,temp,dp,sz);
            }else{
                ans+=helper(ind+1,fl,updcnt,temp,dp,sz);
            }
        }
        return dp[ind][fl][cnt]=ans;
    }
    int countDigitOne(int n) {
        // classic question on digit dp
        if (n == 0) {
            return 0;
        }
        
        int val = n;
        vector<int> temp;
        while (val != 0) {
            temp.push_back(val % 10);
            val /= 10;
        }
        reverse(temp.begin(), temp.end());
        int sz = temp.size();
        // vector<int> dp(sz, -1);
        vector<vector<vector<int>>>dp(sz,vector<vector<int>>(2,vector<int>(15,-1)));
        return helper(0, 0,0 ,temp, dp, sz);
    }
};