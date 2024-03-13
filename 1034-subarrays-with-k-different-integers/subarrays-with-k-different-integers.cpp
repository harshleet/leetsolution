class Solution {
public:
    int helper(vector<int>& nums, int k){
              map<int,int>m;
         int j=0,ans=0;
         for(int i=0;i<nums.size();i++){
             m[nums[i]]++;
            while(m.size()>k && j<=i){
                m[nums[j]]--;
                if(m[nums[j]]==0){
                      m.erase(nums[j]);
                }
                j++;
            }
            ans+=i-j+1;
         }
         return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return helper(nums,k)-helper(nums,k-1);
    }
};