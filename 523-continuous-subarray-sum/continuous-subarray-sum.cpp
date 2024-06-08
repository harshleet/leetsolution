class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n);
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                pre[i] = nums[i] % k;
            } else {
                pre[i] = pre[i - 1] + (nums[i] % k);
                if (pre[i] % k == 0) {
                    return true;
                } else if (m.find(pre[i] % k) != m.end()) {
                    if (m[pre[i] % k] != i - 1) {
                        return true;
                    }
                }
                   
                
            }
            if(m.find(pre[i] % k) == m.end()){
             m[pre[i] % k] = i;}
        }
        return false;
    }
};