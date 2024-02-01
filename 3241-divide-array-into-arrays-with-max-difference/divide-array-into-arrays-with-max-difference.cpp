#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        int j = 0;

        if (nums.size() % 3 != 0) {
            return {};  
        }

        for (int i = 0; i < nums.size(); i += 3) {
            int mini = nums[i];
            int maxi = nums[i + 2];

            if (maxi - mini > k) {
                return {};
            }

            vector<int> temp = {nums[i], nums[i + 1], nums[i + 2]};
            v.push_back(temp);
        }

        return v;
    }
};
