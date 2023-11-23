class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                m[i+j].push_back(nums[i][j]);
            }
        }
        vector<int>ans;
        for(auto it:m){
            reverse(it.second.begin(),it.second.end());
            for(int i=0;i<it.second.size();i++){
                ans.push_back(it.second[i]);
            }
        }
        return ans;
    }
};