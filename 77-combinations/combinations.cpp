class Solution {
public:
void rec(vector<int>&ds,int n,int& k,vector<vector<int>>&s){
    if(ds.size()==k){
        s.push_back(ds);
        return;
    }
    for(int i=1;i<=n;i++){
        if(ds.empty()|| i>ds.back()){
    
      
        ds.push_back(i);
        rec(ds,n,k,s);
        ds.pop_back();
        }
    }
}
    vector<vector<int>> combine(int n, int k) {
         vector<int>ds;
       
     
       vector<vector<int>>s;
        rec(ds,n,k,s);
         
        return s;
    }
};