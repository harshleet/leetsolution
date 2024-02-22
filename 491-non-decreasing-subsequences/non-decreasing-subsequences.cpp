class Solution {
public:
    void helper(int ind,set<vector<int>>&ans,vector<int>ds,vector<int>& nums){
        if(ind>=nums.size()){
            if(ds.size()>=2)
                 ans.insert(ds);
             return;
        }
        if(ds.empty() || ds.back()<=nums[ind]){
        ds.push_back(nums[ind]);
        helper(ind+1,ans,ds,nums);
        ds.pop_back();
}         helper(ind+1,ans,ds,nums);

    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>ds;
       helper(0,ans,ds,nums);
         vector<vector<int>>an(ans.begin(),ans.end());
       return an;
    }
};