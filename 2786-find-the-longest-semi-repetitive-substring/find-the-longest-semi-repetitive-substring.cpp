class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int j = 0, cnt = 0,maxi=1;
        char pre = s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                cnt++;
            }
            if (cnt > 1 && j <= i) {
                if (s[j] == s[j + 1]) {
                    cnt--;
                }
                j++;
            }
            maxi=max(maxi,i-j+1);
        }
        return maxi;
    }
};