#include <algorithm>
#include <string>
#include <set>

class Solution {
public:
    string sortVowels(string s) {
     
        multiset<char> st;

        set<char>s1={'a','e','i','o','u'};
        set<char>s2={'A','E','I','O','U'};
        for(int i=0;i<s.size();i++){
            if(s1.find(s[i])!=s1.end() || s2.find(s[i])!=s2.end()){
                st.insert(s[i]);
            }
        }
        auto it = st.begin();
     
        for (int i = 0; i < s.size(); ++i) {
             if(s1.find(s[i])==s1.end() && s2.find(s[i])==s2.end()){
                continue;
            }else{
                 s[i] = *it;
                it++;
            }
            
        }

        return s;
    }
};
