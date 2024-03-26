class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       
        
        int i = 0;
        while (i < nums.size()) {
            if(nums[i]<=0){
                continue;
            }
            int correct = nums[i] - 1;
            if (nums[i]>0 && correct<nums.size() && nums[i] != nums[correct]) {
                swap(nums[i], nums[correct]);
            } else {
                i++;
            }
        }
        for(int j=0;j<nums.size();j++){
           
            if(nums[j]!=j+1){
                return j+1;
            }
        }
        return nums.size()+1;
    }
};