class Solution {
public:
//same as first but here to use the set 
    void rec(int ind, vector<int>& ds, vector<int>& arr, int n,
             set<vector<int>>& ans) {
        if (n == ind) {
            ans.insert(ds);
            return;
        }

        ds.push_back(arr[ind]);
        rec(ind + 1, ds, arr, n, ans);
        ds.pop_back();
        rec(ind + 1, ds, arr, n, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        rec(0, ds, nums, nums.size(), ans);
        vector<vector<int>> an(ans.begin(), ans.end());
        return an;
    }
};