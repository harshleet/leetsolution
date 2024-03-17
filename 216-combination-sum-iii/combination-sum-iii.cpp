class Solution {
public:
   void helper(int cnt,int sum,vector<vector<int>>&ans,vector<int>ds,map<int,int>&m,int k,int n,int last){
      if(cnt>=k){
        if(sum==n){
            ans.push_back(ds);
        }
        return;
      }
      for(int i=last+1;i<=9;i++){
         if(m[i]==0){
            m[i]=1;
            sum+=i;
            cnt++;
            ds.push_back(i);
            helper(cnt,sum,ans,ds,m,k,n,i);
            ds.pop_back();
            cnt--;
            sum-=i;
            m[i]=0;
         }
      }
   }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        map<int,int>m;
        helper(0,0,ans,ds,m,k,n,0);
        return ans;
    }
};