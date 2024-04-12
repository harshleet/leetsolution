class Solution {
public:
    int trap(vector<int>& height) {
        int maxi = height[0], n = height.size(), maxi2 = height[n - 1];
        ;
        vector<int> mf(n, -1);
        vector<int> mb(n, -1);
        for (int i = 1; i < n; i++) {
            if (height[i] < maxi) {
                mf[i] = maxi;
            }
            maxi = max(maxi, height[i]);
            
            if (height[n - 1 - i] < maxi2) {
                mb[n - 1 - i] = maxi2;
            }
            maxi2 = max(maxi2, height[n - 1 - i]);
           
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (mb[i] == -1 || mf[i] == -1) {
                continue;
            } else {
                ans += min(mb[i], mf[i]) - height[i];
            }
        }
        return ans;
    }
};