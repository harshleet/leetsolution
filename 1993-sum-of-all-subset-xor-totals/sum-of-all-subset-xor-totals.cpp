class Solution {
public:
    void helper(int ind, vector<int>& nums, int x, int& sum) {
        if (ind >= nums.size()) {
            sum += x;
            return;
        }
        helper(ind + 1, nums, x, sum);
        cout<<nums[ind]<<" ";
        x ^= nums[ind];
        helper(ind + 1, nums, x, sum);
        x ^= nums[ind];
    }
    int subsetXORSum(vector<int>& nums) {

        int sum = 0;
        helper(0, nums, 0, sum);
        return sum;
    }
};