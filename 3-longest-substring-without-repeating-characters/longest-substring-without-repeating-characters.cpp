class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j=0,maxi=0;
        map<int,int>m;
        for(int i=0;i<s.size();i++){
               m[s[i]]++;
               while(m[s[i]]>1){
                  m[s[j]]--;
                  j++;
               }
               maxi=max(maxi,i-j+1);
        }
        return maxi;
    }
};