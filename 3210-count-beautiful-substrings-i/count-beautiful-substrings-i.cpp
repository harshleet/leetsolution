class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        set<char> vo = { 'a', 'e', 'i', 'o', 'u' };
        int n = s.length();
        int a = 0;

       for (int i = 0; i < s.length(); i++) {
        int v=0,c=0;
        for (int j = i; j < s.length(); j++) {
            if (vo.count(s[j])) {
                        v++;
                    } else {
                        c++;
                    }
              if (v == c && (v * c) % k == 0) {
                    a++;
              }
        }

    }
       
        return a;

    }
};