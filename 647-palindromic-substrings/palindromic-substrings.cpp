class Solution {
public:
    bool check(string &s){
          for(int i=0;i<s.size()/2;i++){
              if(s[i]!=s[s.size()-1-i]){
                  return false;
              }
          }
          return true;
    }
    int countSubstrings(string s) {
        int c=0;
        for(int size=1;size<=s.size();size++){
            for(int i=0;i<=s.size()-size;i++){
                string a=s.substr(i,size);
                if(check(a)){
                    c++;
                }
            }
        }
        return c;
    }
};