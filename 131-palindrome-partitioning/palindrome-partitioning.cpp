class Solution {
public:
     bool isPalindrome(string &temp){
         for(int i=0;i<temp.size()/2;i++){
             if(temp[i]!=temp[temp.size()-1-i]){
                 return false;
             }
         }
         return true;
     }
    void helper(int ind,string s, vector<string>&ds,vector<vector<string>>&ans){
         if(ind>=s.size()){
             if(!ds.empty()){
                 ans.push_back(ds);
             }
             return;
         }

         for(int i=1;i<=s.size()-ind;i++){
             string temp=s.substr(ind,i);
             if(isPalindrome(temp)){
                    ds.push_back(temp);
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