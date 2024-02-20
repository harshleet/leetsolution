class Solution {
public:
bool isPalindrome(string &s){
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i]){
            return false;
        }
    }
    return true;
}
    void helper(int ind,string &s,vector<string>&ds,vector<vector<string>>&ans){
        if(ind>=s.size()){
            if(!ds.empty()){
                ans.push_back(ds);
            }
            return;
        }
        for(int i=1;i<=s.size()-ind;i++){
             string st=s.substr(ind,i);
             if(isPalindrome(st)){
                 ds.push_back(st);
                 helper(ind+i,s,ds,ans);
                 ds.pop_back();
             }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        helper(0,s,ds,ans);
        return ans;
    }
};