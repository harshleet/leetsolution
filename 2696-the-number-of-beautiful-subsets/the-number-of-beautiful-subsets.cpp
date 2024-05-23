class Solution {
public:
    void helper(int ind, vector<int>& nums, int k, vector<int>& m, int& ans) {
        if (ind >= nums.size()) {

            ans++;

            return;
        }
        helper(ind + 1, nums, k, m, ans);
        if ((nums[ind] - k) <0 || m[nums[ind] - k] == 0) {
            m[nums[ind]]++;
            helper(ind + 1, nums, k, m, ans);
            m[nums[ind]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {

        int ans = 0;
        sort(nums.begin(), nums.end());
        vector<int> m(1001, 0);
        helper(0, nums, k, m, ans);
        return ans - 1;
    }
};