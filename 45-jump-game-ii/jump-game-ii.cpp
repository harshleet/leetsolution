class Solution {
public:
    struct compare {
        bool operator()(const std::pair<int, int>& p1,
                        const std::pair<int, int>& p2) {
            if (p1.first == p2.first) {
                return p1.second > p2.second;
            }
            return p1.first < p2.first;
        }
    };
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        // greeedy se try krte
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

        int ans = 0;
        int l = 0, r = 0;
        // if (r >= nums.size() - 1) {
        //     return 1;
        // }
        while (r < nums.size()-1) {
            int maxi = 0;
            for (int i = l; i <= r; i++) {
                maxi = max(maxi, nums[i] + i);
            }

            l = r + 1;
            r = maxi;
            ans++;
        }

        return ans;
    }
};