class Solution {
public:
void helper(vector<string>&ans,string&ds,string&s,int ind,map<int,bool>&m){
    if(ind==s.size()){
      ans.push_back(ds);
      return;
    }
   
        if(isalpha(s[ind])){
       
        ds.push_back(tolower(s[ind]));
    
        helper(ans,ds,s,ind+1,m);
        ds.pop_back();
      
        ds.push_back(toupper(s[ind]));
       
        helper(ans,ds,s,ind+1,m);
         ds.pop_back();
     
        }else {
            ds.push_back(s[ind]);
            helper(ans, ds, s, ind+1, m);
            ds.pop_back();
        }
   
}
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        string ds="";
        map<int,bool>m;
        helper(ans,ds,s,0,m);
        return ans;
     //easy question make not make backtracking   
    }
};