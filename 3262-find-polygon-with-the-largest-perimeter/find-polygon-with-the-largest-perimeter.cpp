class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long maxi=nums[0]+nums[1],sum=nums[0]+nums[1];
        long long f=0;
        for(int i=2;i<nums.size();i++){
            if(nums[i]<sum){
                maxi=sum+nums[i];
                f=1;
            }
            sum+=nums[i];
        }
        if(f==0){
            return -1;
        }
        return maxi;
    }
};