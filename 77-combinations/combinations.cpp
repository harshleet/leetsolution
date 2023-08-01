class Solution {
public:
void rec(vector<int>&ds,int n,int& k,map<int,bool>&m,set<vector<int>>&s){
    if(ds.size()==k){
        s.insert(ds);
        return;
    }
    for(int i=1;i<=n;i++){
        if(ds.empty()|| i>ds.back()){
        if(m[i]==false ){
        m[i]=true;
        ds.push_back(i);
        rec(ds,n,k,m,s);
        ds.pop_back();
        m[i]=false;}}
    }
}
    vector<vector<int>> combine(int n, int k) {
         vector<int>ds;
        map<int,bool>m;
        for(int i=1;i<=n;i++){
            m[i]=false;
        }
     
       set<vector<int>>s;
        rec(ds,n,k,m,s);
          vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};