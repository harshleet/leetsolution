class Solution {
public:
void helper(vector<int>&nums,int ind,vector<int>&ds,vector<vector<int>>&ans){
    if(ind>=nums.size()){
      
            ans.push_back(ds);
           
        
        return;
    }
    ds.push_back(nums[ind]);
    helper(nums,ind+1,ds,ans);
    ds.pop_back();
    helper(nums,ind+1,ds,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        helper(nums,0,ds,ans);
        return ans;
    }
};