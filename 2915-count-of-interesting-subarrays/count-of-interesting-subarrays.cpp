class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
   
    int n = nums.size();
   vector<int> prefix(n + 1, 0);
    unordered_map<int, int> count;

    long long result = 0;

    prefix[0] = 0;
    count[0] = 1;

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = (prefix[i] + (nums[i] % modulo == k ? 1 : 0)) % modulo;
        int complement = (prefix[i + 1] - k + modulo) % modulo;
        result += count[complement];
        count[prefix[i + 1]]++;
    }

    return result;

    }
};