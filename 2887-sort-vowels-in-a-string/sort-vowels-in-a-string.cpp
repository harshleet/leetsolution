class Solution {
public:
    string sortVowels(string s) {
        vector<char>v;
        set<char>s1={'a','e','i','o','u'};
        set<char>s2={'A','E','I','O','U'};
        for(int i=0;i<s.size();i++){
            if(s1.find(s[i])!=s1.end() || s2.find(s[i])!=s2.end()){
                v.push_back(s[i]);
            }
        }
        sort(v.begin(),v.end());
        int j=0;
         for(int i=0;i<s.size();i++){
            if(s1.find(s[i])==s1.end() && s2.find(s[i])==s2.end()){
                continue;
            }else{
                s[i]=v[j];
                j++;
            }
        }
        return s;
    }
};