class Solution {
public:
    void helper(int ind,map<int,bool>&m,vector<int>&ds,int& n,set<vector<int>>&s){
        if(ds.size()==n){
            s.insert(ds);
            return;
        }
        for(int i=1;i<=n;i++){
           if(m[i]==false && (i%ind==0 || ind%i==0)){
               m[i]=true;
               ds.push_back(i);
               helper(ind+1,m,ds,n,s);
               m[i]=false;
               ds.pop_back();
               
           }
        }
    }
    int countArrangement(int n) {
        map<int,bool>m;
        vector<int>ds;
        set<vector<int>>s;
        for(int i=1;i<n;i++){
            m[i]=false;
        }
        helper(1,m,ds,n,s);
        return s.size();
    }
};