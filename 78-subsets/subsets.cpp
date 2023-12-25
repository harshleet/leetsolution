class Solution {
public:
void rec(int ind,int size,vector<int>&ds,vector<vector<int>>&ans,vector<int>&nums){
    if(ind==size){
         
               ans.push_back(ds);
        return;
    }
     rec(ind+1,size,ds,ans,nums);
    ds.push_back(nums[ind]);
    rec(ind+1,size,ds,ans,nums);
    ds.pop_back();
   
}
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>>ans;
         vector<int>ds;
          rec(0,nums.size(),ds,ans,nums);
          return ans;
    }
};