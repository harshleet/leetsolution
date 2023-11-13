#include <algorithm>
#include <string>
#include <set>

class Solution {
public:
    string sortVowels(string s) {
        set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        multiset<char> st;

        for (int i = 0; i < s.size(); ++i) {
            if (vowels.find(s[i]) != vowels.end()) {
                st.insert(s[i]);
            }
        }

        auto it = st.begin();
     
        for (int i = 0; i < s.size(); ++i) {
            if (vowels.find(s[i]) != vowels.end()) {
                s[i] = *it;
                it++;
            }
        }

        return s;
    }
};
