class Solution {
public:
    void helper(int ind,vector<int>&nums,set<vector<int>>&ans,vector<int>&ds){
        if(ind>=nums.size()){
            
                ans.insert(ds);
           
            return;
        }
        helper(ind+1,nums,ans,ds);
        ds.push_back(nums[ind]);
        helper(ind+1,nums,ans,ds);
        ds.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>ds;
        helper(0,nums,ans,ds);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};