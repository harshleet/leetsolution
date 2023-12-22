class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int mini=nums[0];
        int maxi=0;
        for(int i=1;i<nums.size();i++){
            maxi=max(nums[i]-mini,maxi);
            mini=min(mini,nums[i]);
        } 
        return maxi;
    }
};