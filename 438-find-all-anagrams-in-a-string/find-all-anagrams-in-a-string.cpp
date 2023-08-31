class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int j = 0;
        vector<int> v(26, 0);
        vector<int> ori(26, 0);
        for (int i = 0; i < p.size(); i++) {
            ori[p[i] - 'a']++; 
        }
        vector<int> ans;
        for (int i = 0; i < s.size(); i++) {
            v[s[i] - 'a']++;

            
            while (i - j + 1 > p.size()) {
                v[s[j] - 'a']--;
                j++;
            }
            if (v == ori) {
                ans.push_back(j);
            }
        }
        return ans;
    }
};
