class Solution {
public:
   void helper(int n,int k,vector<int>&ds,vector<vector<int>>&ans,int st){
       if(ds.size()==k){
           ans.push_back(ds);
           return;
       }
       for(int i=st;i<=n;i++){
           if(ds.size()<k){
               ds.push_back(i);
               helper(n,k,ds,ans,i+1);
               ds.pop_back();
           }
       }
   }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>ds;
        helper(n,k,ds,ans,1);
        return ans;

    }
};