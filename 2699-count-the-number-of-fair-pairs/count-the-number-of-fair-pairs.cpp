class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        //o(n^2 solun)
       sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<nums.size();i++){
         
            auto lowerIt = lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i]);
            auto upperIt = upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i]);
            long long count = std::distance(lowerIt, upperIt);
            ans+=count;
            
        }return ans;
    }
};