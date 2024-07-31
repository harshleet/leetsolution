class Solution {
public:
 int helper(int ind,vector<vector<int>>&books,int selfWidth,vector<int>&dp){
    if(ind>=books.size()){
        return 0;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int mini=INT_MAX;
    int maxi=0;
    int curwid=0;
    int i;
    for(i=ind;i<books.size();i++){
        if(curwid+books[i][0]<=selfWidth){
            curwid+=books[i][0];
            maxi=max(maxi,books[i][1]);
            mini=min(mini,maxi+helper(i+1,books,selfWidth,dp));
        }else{
            break;
        }
    }
    return dp[ind]=min(mini,maxi+helper(i,books,selfWidth,dp));
 }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int>dp(books.size(),-1);
        return helper(0,books,shelfWidth,dp);
    }
};