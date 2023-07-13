class Solution {
public:
    void helper(int& tot,string& ds,vector<string>&ans,vector<char>&brac,int open,int close,int ind){
        if(ind==tot ){
            if( open==tot/2 && close==tot/2)
                 ans.push_back(ds);
            return;
        }
        for(int i=0;i<2;i++){
            if(brac[i]=='('){
                ds+=brac[i];
                helper(tot,ds,ans,brac,open+1,close,ind+1);
                ds.pop_back();
            }else{
                if(open>close){
                     ds+=brac[i];
                     helper(tot,ds,ans,brac,open,close+1,ind+1);
                     ds.pop_back();
                }
            }

        }
    }
    vector<string> generateParenthesis(int n) {
        int tot=2*n;
        vector<char>brac={'(',')'};
        string ds="";
        vector<string>ans;
        helper(tot,ds,ans,brac,0,0,0);
        return ans;
    }
};