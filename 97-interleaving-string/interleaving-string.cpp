class Solution {
public:
    int helper(int ind1,int ind2,int ind3,string&s1,string&s2,string&s3,vector<vector<vector<int>>>&dp){
        if(ind1==s1.size() && ind2==s2.size()&& ind3==s3.size()){
            return 1;
        }if(ind3==s3.size())return 0;

        if(dp[ind1][ind2][ind3]!=-1){
            return dp[ind1][ind2][ind3];
        }
        bool one=0,two=0;
        if(s1[ind1]==s3[ind3]){
            one=helper(ind1+1,ind2,ind3+1,s1,s2,s3,dp);
        }
         if(s2[ind2]==s3[ind3]){
            two=helper(ind1,ind2+1,ind3+1,s1,s2,s3,dp);
        }
        return dp[ind1][ind2][ind3]=one|two;

    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>>dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1)));
        return helper(0,0,0,s1,s2,s3,dp);
    }
};