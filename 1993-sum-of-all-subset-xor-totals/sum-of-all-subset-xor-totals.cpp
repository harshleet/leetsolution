class Solution {
public:
    void helper(int ind, vector<int>& nums, int x, int& sum) {
        if (ind >= nums.size()) {
            sum += x;
            return;
        }
        helper(ind + 1, nums, x, sum);

        x ^= nums[ind];
        helper(ind + 1, nums, x, sum);
        x ^= nums[ind];
    }
    int subsetXORSum(vector<int>& nums) {

        int sum = 0;
        int cont = pow(2, nums.size() - 1);
        int orr = 0;
        for (int i = 0; i < nums.size(); i++) {
            orr |= nums[i];
        }
        int i=0;
        while (orr!=0) {
            if (orr & 1 == 1) {
                sum += (cont * pow(2, i));
            }
            i++;
            orr=orr>>1;
        }
        return sum;
    }
};