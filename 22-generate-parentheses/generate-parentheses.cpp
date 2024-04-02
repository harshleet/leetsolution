class Solution {
public:
    void helper(string ds,int op,int cl,int n,vector<string>&ans){
        if(op>=n){
            while(op>cl){
                ds.push_back(')');
                cl++;
            }
            ans.push_back(ds);
            return;
        }
        ds.push_back('(');
        helper(ds,op+1,cl,n,ans);
        ds.pop_back();
        if(op>cl){
             ds.push_back(')');
             helper(ds,op,cl+1,n,ans);
             ds.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        
         helper("",0,0,n,ans);
         return ans;
    }
};