class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        int c=0;
        map<int,int>m;
            for(int i=0;i<nums.size();i++){
                m[nums[i]]++;
                c=max(c,m[nums[i]]);
            }
        vector<vector<int>>ans(c);
        for(auto it:m){
            for(int i=0;i<it.second;i++){
                ans[i].push_back(it.first);
            }
        }
        
        return ans;
    }
};