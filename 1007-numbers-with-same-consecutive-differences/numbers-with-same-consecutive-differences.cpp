class Solution {
public:
   void helper(int val,int pre,int dig,set<int>&ans,int n,int k){
       if(dig==n){
          ans.insert(val);
          return ;
       }
      if(pre==-1){
        for(int i=1;i<=9;i++){
            helper(val*10+i,i,dig+1,ans,n,k);
        }
        return;
      }
      if(pre+k<=9){
        helper(val*10+pre+k,pre+k,dig+1,ans,n,k);
      }
       if(pre-k>=0){
        helper(val*10+pre-k,pre-k,dig+1,ans,n,k);
      }
   }
    vector<int> numsSameConsecDiff(int n, int k) {
        int ds=0;
        set<int>ans;
        helper(0,-1,0,ans,n,k);
        return vector<int>(ans.begin(),ans.end());
    }
};