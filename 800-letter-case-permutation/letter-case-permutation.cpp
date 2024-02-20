class Solution {
public:
void helper(string ds,int ind,vector<string>&ans,string s){
    if(ind>=s.size()){
        if(!ds.empty()){
            ans.push_back(ds);
        }
        return;
    }
    if(isalpha(s[ind])){
        if(isupper(s[ind])){
              ds.push_back(tolower(s[ind]));
              helper(ds,ind+1,ans,s);
              ds.pop_back();
        }else if(islower(s[ind])){
              ds.push_back(toupper(s[ind]));
              helper(ds,ind+1,ans,s);
              ds.pop_back();
        }
    }
        ds.push_back(s[ind]);
        helper(ds,ind+1,ans,s);
    
}
    vector<string> letterCasePermutation(string s) {
       vector<string>ans;
       helper("",0,ans,s);
       return ans;
    }
};