class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> m;
        vector<int> temp(66, 0);
        int cnt=0;
        set<char> st;
        for (int i = 0; i < t.size(); i++) {
            m[t[i] - 'A']++;
            st.insert(t[i]);
        }
        int mini=INT_MAX;
        int minii=-1,  minij=-1;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            m[s[i] - 'A']--;
            if (st.find(s[i]) != st.end() && m[s[i]-'A']==0) {   
                cnt++;
            }

           
            while (cnt==st.size() && j <= i) {
            
                if(mini>i-j+1){
                    mini=i-j+1;
                    minii=i;
                    minij=j;
                }
                m[s[j]-'A']++;
                if(st.find(s[j])!=st.end() && m[s[j]-'A']>0){
                    cnt--;
                }
                j++;
            }
        }
        if(minii==-1 && minij==-1){
            return "";
        }
        return s.substr(minij,minii-minij+1);
    }
};