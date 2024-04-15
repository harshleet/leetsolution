class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int j=0,sum=0,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
           sum+=nums[i];
            maxi=max(maxi,sum);
           while(sum<0 ){
               sum-=nums[j];
               j++;
           }
          
        }
        return maxi;
    }
};