class Solution {
public:
    void helper(int ind,int sum,set<vector<int>>&ans,vector<int>&ds,vector<int>& candidates, int target){
        if(ind>=candidates.size()){
            if(sum==target){
                ans.insert(vector<int>(ds.begin(),ds.end()));
            }
            return;
        }
       
        if(sum+candidates[ind]<=target){
        ds.push_back(candidates[ind]);
        helper(ind+1,sum+candidates[ind],ans,ds,candidates,target);
        ds.pop_back();}

        while(ind+1<candidates.size() && candidates[ind]==candidates[ind+1]){
          ind++;
        }
         helper(ind+1,sum,ans,ds,candidates,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        vector<int>ds;
        helper(0,0,ans,ds,candidates,target);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};