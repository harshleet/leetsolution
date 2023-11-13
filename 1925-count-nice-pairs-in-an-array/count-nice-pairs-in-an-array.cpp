class Solution {
public:
    int MOD = 1e9 + 7;

    int countNicePairs(vector<int>& nums) {
        vector<int> rev(nums.size());
        unordered_map<int, int> m;
             long long cnt = 0; 
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i], reverse = 0, remainder;
            while (n != 0) {
                remainder = n % 10;
                reverse = reverse * 10 + remainder;
                n /= 10;
            }
            rev[i] = reverse;
             if (m.find(nums[i] - rev[i]) != m.end()) {
                cnt = (cnt + m[nums[i] - rev[i]]) % MOD;
            }
            m[nums[i] - rev[i]]++;
        }
       return cnt;
     

       
    }
};
