class Solution {
public:
    void helper(int ind,int sum,vector<int>& candidates, int target, vector<vector<int>>&ans,vector<int>&ds){
       if(ind>=candidates.size()){
           if(sum==target && !ds.empty()){
               ans.push_back(ds);
           }
           return;
       }
       if(sum+candidates[ind]<=target){
           ds.push_back(candidates[ind]);
           helper(ind,sum+candidates[ind],candidates,target,ans,ds);
           ds.pop_back();
       }
       helper(ind+1,sum,candidates,target,ans,ds);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        helper(0,0,candidates,target,ans,ds);
        return ans;

    }
};