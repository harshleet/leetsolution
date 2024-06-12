class Solution {
public:
    int helper(int low,int high,vector<int>&nums){
        int i=low;
        int j=high;
        int pivot=nums[low];

        while(i<j){
            while(pivot>=nums[i] && i<high){
                i++;
            }
            while(pivot<nums[j] && j>low){
                j--;
            }
            if(i<j){
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[low],nums[j]);
        return j;
    }
    void quick_sort(int low,int high,vector<int>&nums){
        if(low<high){
            int p=helper(low,high,nums);
            quick_sort(low,p-1,nums);
            quick_sort(p+1,high,nums);
        }
    }
    void sortColors(vector<int>& nums) {
        quick_sort(0,nums.size()-1,nums);
        return;
    }
};