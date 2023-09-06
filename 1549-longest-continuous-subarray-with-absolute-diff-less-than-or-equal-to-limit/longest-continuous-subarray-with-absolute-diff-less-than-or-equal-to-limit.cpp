class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int maxi = 0;
        multiset<int> m;
        int left = 0;

        for (int right = 0; right < n; right++) {
            m.insert(nums[right]);

            while (*m.rbegin() - *m.begin() > limit) {
                m.erase(m.find(nums[left]));
                left++;
            }

            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};
