class Solution {
public:
    void helper(int ind,int n,vector<string>ds,vector<vector<string>>&ans,map<int,int>&c,map<int,int>&ld,map<int,int>&rd){
        if(ind>=n){
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<n;i++){
           if(c[i]==0 && ld[n-ind+i]==0 && rd[i+ind]==0){
            c[i]=1;
            ld[n-ind+i]=1;
            rd[i+ind]=1;
            ds[ind][i]='Q';
            helper(ind+1,n,ds,ans,c,ld,rd);
            c[i]=0;
            ld[n+i-ind]=0;
            rd[i+ind]=0;
            ds[ind][i]='.';
           }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>ds(n);
        for(int i=0;i<n;i++){
            string s(n,'.');
            ds[i]=s;
        }
        map<int,int>c;
        map<int,int>ld;
        map<int,int>rd;
        vector<vector<string>>ans;
        helper(0,n,ds,ans,c,ld,rd);
        
        return ans;
    }
};