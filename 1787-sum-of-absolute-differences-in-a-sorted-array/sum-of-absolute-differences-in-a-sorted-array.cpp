class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int>pre(nums.size(),0);
        int val=0;
        for(int i=0;i<nums.size();i++){
            val+=nums[i];
            pre[i]=val;
        }
        vector<int>ans(nums.size());
         for(int i=0;i<nums.size();i++){
             int fr=nums.size()-i;
             int ba=i;
        
          int v2=0,v=val;
          if(i>=1){
              v-=pre[i-1];
              v2+=pre[i-1];
          }
          v-=(nums[i]*fr);
          v2=(nums[i])*ba-v2;
          ans[i]=v+v2;
        }
        return ans;
    }
};