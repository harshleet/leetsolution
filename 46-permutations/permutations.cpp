class Solution {
public:
vector<vector<int>>ans;
void rec(vector<int>&ds,vector<int>&arr,int n, map<int,bool>&m){
        if(ds.size()==n)
           {
               
                   ans.push_back(ds);
                   return;
           }
         
  for(int i=0;i<arr.size();i++){
      if(m[i]==false)
      {
             ds.push_back(arr[i]);
             m[i]=true;
            rec(ds,arr,n,m);
            ds.pop_back();
             m[i]=false;
          }
      }
  
}
    vector<vector<int>> permute(vector<int>& nums) {
         vector<int>ds;
        map<int,bool>m;
        for(int i=0;i<nums.size();i++){
            m[i]=false;
        }
        rec(ds,nums,nums.size(),m);
        return ans;
    }
};