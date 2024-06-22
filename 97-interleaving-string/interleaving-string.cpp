class Solution {
public:
    bool helper(int ind1,int ind2,int ind3,string s1, string s2, string s3,vector<vector<int>>&dp){
        // cout<<ind1<<" "<<ind2<<" "<<ind3<<endl;
        if(ind3==s3.size()){
            return true;
        }
       if(dp[ind1][ind2]!=-1){
        return dp[ind1][ind2];
       }
        bool ans=false;
        if(ind1<s1.size()&& s1[ind1]==s3[ind3] ){
            ans=ans|helper(ind1+1,ind2,ind3+1,s1,s2,s3,dp);
        }
        if(ind2<s2.size() && s2[ind2]==s3[ind3]){
            ans=ans|helper(ind1,ind2+1,ind3+1,s1,s2,s3,dp);
        }
       
        return dp[ind1][ind2]=ans;

    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()){
            return false;
        }
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return helper(0,0,0,s1,s2,s3,dp);
    }
};