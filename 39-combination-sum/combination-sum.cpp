class Solution {
public:
   void helper(vector<vector<int>>&ans,vector<int>ds,int ind,vector<int>& candidates, int target){
       if(ind>=candidates.size()){
           if(target==0){
               ans.push_back(ds);
               ds.clear();
           }
           return;
       }
      
       if(candidates[ind]<=target){
       ds.push_back(candidates[ind]);
       helper(ans,ds,ind,candidates,target-candidates[ind]);;
       ds.pop_back();}
        helper(ans,ds,ind+1,candidates,target);
   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        helper(ans,ds,0,candidates,target);
        return ans;
    }
};
