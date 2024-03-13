class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int>m;
        int cnt=0,j=0;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            while(m['a']>=1 && m['b']>=1 && m['c']>=1){
                cnt+=s.size()-i;
                m[s[j]]--;
                j++;

            }
        }
        return cnt;
    }
};