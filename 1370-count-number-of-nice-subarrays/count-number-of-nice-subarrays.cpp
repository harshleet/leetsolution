class Solution {
public:
    int helper(vector<int>& nums, int k){
        int cnt=0,j=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1){
                cnt++;
            }
            while(cnt>k && j<=i){
                if(nums[j]%2==1){
                 cnt--;
               }
               j++;
            }

             ans+=i-j+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};