class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<=4){
            return 0;
        }
        int n=nums.size();
        return min({nums[n-1]-nums[3],nums[n-4]-nums[0],nums[n-2]-nums[2],nums[n-3]-nums[1]});
    }
};