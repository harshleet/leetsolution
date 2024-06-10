class Solution {
public:
bool static cmp(string& s1,string &s2){
    return s1.size()<s2.size();
}
bool check(string& s1, string& s2){
    if(s1.size() != s2.size() + 1) return false;
    
    int first = 0;
    int second = 0;
    
    while(first < s1.size()){
        if(second < s2.size() && s1[first] == s2[second]){
            first ++;
            second ++;
        }
        else first ++;
    }
    if(first == s1.size() && second == s2.size()) return true;
    else return false; 
}
  int f(vector<string>&nums,vector<vector<int>>&dp,int i,int pre){
       if(i==nums.size()){
           return 0;
       }
       if(dp[i][pre+1]!=-1){
           return dp[i][pre+1];
       }
         int ntake=f(nums,dp,i+1,pre);
       int take=0;
       if(pre==  -1 ||  check(nums[i],nums[pre])){
          take=1+f(nums,dp,i+1,i);
       }
     
       return dp[i][pre+1]=max(take,ntake);
    }
    int longestStrChain(vector<string>& nums) {
        sort(nums.begin(),nums.end(),cmp);
         vector<int>dp(nums.size(),1);
         int gmax=1;
          for(int ind=0;ind<nums.size();ind++){
            int maxi=1;
              for(int pre=0;pre<ind;pre++){
                if(check(nums[ind],nums[pre])){
                    maxi=max(maxi,1+dp[pre]);
                }
              }
              dp[ind]=maxi;
              gmax=max(gmax,maxi);
          }
          return gmax;
    }
};