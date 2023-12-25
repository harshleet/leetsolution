class Solution {
public:
    void helper(int k,int n,int ind,set<int>&ds,set<vector<int>>&ans){
       
       
             if( ds.size()==k){
                 if(n==0){
                vector<int> d(ds.begin(), ds.end());
                ans.insert(d);
               }
                return ;
             }
             
        for(int i=ind;i<=9;i++){
            if(i<=n){
                ds.insert(i);
                helper(k,n-i,i+1,ds,ans);
                ds.erase(i);
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        set<int>ds;
        set<vector<int>>ans;
        helper(k,n,1,ds,ans);
        vector<vector<int>>an(ans.begin(),ans.end());
        return an;
    }
};