class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0,n=nums.size();
        while(i<nums.size()){
            if(nums[i]==n)i++;
            else if(i!=nums[i])
            swap(nums[i],nums[nums[i]]);
            else 
            i++;
        }
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=j){
                return j;
            }
        }
        return nums.size();
    }
};