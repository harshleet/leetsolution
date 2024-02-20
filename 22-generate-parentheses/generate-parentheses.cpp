class Solution {
public:
    void helper(string ds,int op,int cl,vector<string>&ans,int n){
        if(op>=n){
            if(!ds.empty()){
                while(op>cl){
                    ds.push_back(')');
                    cl++;
                }
                ans.push_back(ds);
            }
            return;
        }
        if(op>cl){
            ds.push_back(')');
            helper(ds,op,cl+1,ans,n);
            ds.pop_back();
        }
        if(op<n){
           ds.push_back('(');
            helper(ds,op+1,cl,ans,n);
            ds.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string ds;
        helper("",0,0,ans,n);
        return ans;
    }
};