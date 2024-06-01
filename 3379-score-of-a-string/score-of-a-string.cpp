class Solution {
public:
    int scoreOfString(string s) {
        int pre=s[0],c=0;
        
        for(int i=1;i<s.size();i++){
            c+=abs(int(s[i])-pre);
            pre=s[i];
        }
        return c;
    }
};