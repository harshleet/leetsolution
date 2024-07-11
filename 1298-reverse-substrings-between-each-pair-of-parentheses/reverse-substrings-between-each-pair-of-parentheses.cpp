class Solution {
public:
    string reverseParentheses(string s) {
      
        map<int,string>mp;
        int cn=0;
        string ans="";
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cn++;
            }else if(s[i]==')'){
                string temp=mp[cn];
                reverse(temp.begin(),temp.end());
                mp[cn]="";
                cn--;
                mp[cn]+=temp;
              
            }else{
                mp[cn]+=s[i];
            }
        }
        return mp[0];
    }
};