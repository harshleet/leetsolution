class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        if(nums.size()==1 ||nums.size()==2){
            return true;
        }
       
        int low=0,high=1;
        while(high<nums.size()){
            if(nums[low]+nums[high]>=m){
                return true;
            }
            low=high;
            high++;

        }
        return false;
    }
};