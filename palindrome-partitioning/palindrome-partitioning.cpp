class Solution {
public:
    bool isPalindrome(string& s){
          for(int i=0;i<s.length()/2;i++){
              if(s[i]!=s[s.length()-1-i]){
                 return false;
              }
          }
          return true;
    }
    void helper(int ind,string& s,vector<string>&ds,vector<vector<string>>&ans){
        if(ind==s.length()){
            ans.push_back(ds);
            return;
        }
        string st="";
        for(int i=ind;i<s.size();i++){
            st+=s[i];
            if(isPalindrome(st)){
                ds.push_back(st);
                helper(i+1,s,ds,ans);//yaha index nhi ayega bhai i+1 hi aayega
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        //to do tommorow
        vector<string>ds;
        vector<vector<string>>ans;
        helper(0,s,ds,ans);
        return ans;

    }
};