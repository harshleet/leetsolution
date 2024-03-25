class Solution {
public:
    void helper(string ds,vector<int>&ans,int no,int n){
       
         int val=stoi(ds);
        if(val>n){
            return;
        }
        ans.push_back(val);
        for(char i='0';i<='9';i++){
            ds+=i;
            helper(ds,ans,no,n);
            ds.pop_back();
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        int no=log10(n);
        string ds="";
        for(char i='1';i<='9';i++){
            ds+=i;
            helper(ds,ans,no,n);
            ds.pop_back();
        }
        return ans;
    }
};