class Solution {
public:
void helper(string& ds,string& digits,vector<string>&ans,int ind,map<int,string>&m){
    if(ds.size()==digits.size()){
        ans.push_back(ds);
    }
     string st=m[digits[ind] - '0'];
    for(int i=0;i<st.size();i++){
        ds+=st[i];
        helper(ds,digits,ans,ind+1,m);
        ds.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        map<int,string>m;
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";

        if(digits==""){
            return {};
        }
        string ds="";
        vector<string>ans;
        helper(ds,digits,ans,0,m);
        return ans;
    }
};