class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int ans = 0;
        int left = 0, right = s.size() - 1;
        while (left < right) {

            int l = left, r = right;

            while (l <= r && s[l] != s[r]) {
                r--;
            }
            if (l == r) {
                while (r < right) {
                    swap(s[r], s[r + 1]);
                   
                    r++;
                  
                }
               
               continue;
            } else {
                while (r < right) {
                    swap(s[r], s[r + 1]);
                    r++;
                    ans++;
                }
                left++;
               right--;
            }
            
        }
        cout<<s<<" ";

        return ans;
    }
};