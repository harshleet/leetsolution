class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0,pre=nums[0];
        for(int i=1;i<nums.size();i++){
              if(nums[i]<=pre){
                ans+=pre-nums[i]+1;
                pre=pre+1;
              }else{
                pre=nums[i];
              }
        }
        return ans;
    }
};