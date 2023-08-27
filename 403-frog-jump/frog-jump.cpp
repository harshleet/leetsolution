class Solution {
public:
bool helper(int ind,int jump,vector<vector<int>>&dp,vector<int>&stones,map<int,int>&m){
    if(ind==stones.size()-1){
        return true;
    }
    if(dp[ind][jump]!=-1){
        return dp[ind][jump];
    }
    bool op1=false,op2=false,op3=false;

    if(m.find(stones[ind]+jump-1)!=m.end() && jump>1){
       op1=helper(m[stones[ind]+jump-1],jump-1,dp,stones,m);
    }
    if(m.find(stones[ind]+jump)!=m.end()){
         op2=helper(m[stones[ind]+jump],jump,dp,stones,m);
    }
    if(m.find(stones[ind]+jump+1)!=m.end()&& ind!=0){
         op3=helper(m[stones[ind]+jump+1],jump+1,dp,stones,m);
    }
    return dp[ind][jump]=(op1||op2)||op3;
}
    bool canCross(vector<int>& stones) {
        vector<vector<int>>dp(stones.size(),vector<int>(stones.size(),-1));
        map<int,int>m;
        for(int i=0;i<stones.size();i++){
             m[stones[i]]=i;
        }
        return helper(0,1,dp,stones,m);
    }
};