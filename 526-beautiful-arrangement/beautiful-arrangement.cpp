class Solution {
public:
    int helper(int ind,map<int,bool>&m,vector<int>&ds,int& n,set<vector<int>>&s){
        if(ds.size()==n){
            return 1;
        }
        int a=0;
        for(int i=1;i<=n;i++){
           if(m[i]==false && (i%ind==0 || ind%i==0)){
               m[i]=true;
               ds.push_back(i);
               a+=helper(ind+1,m,ds,n,s);
               m[i]=false;
               ds.pop_back();
               
           }
        }
        return a;
    }
    int countArrangement(int n) {
        map<int,bool>m;
        vector<int>ds;
        set<vector<int>>s;
        for(int i=1;i<n;i++){
            m[i]=false;
        }
        int a=helper(1,m,ds,n,s);
        return a;
    }
};