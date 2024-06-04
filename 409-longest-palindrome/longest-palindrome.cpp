class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        int ans=0,od=0;
        for(auto it:m){
                ans+=(it.second/2)*2;
                od+=it.second%2;
        }
        return ans+min(1,od);
    }
};