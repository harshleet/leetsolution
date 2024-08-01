class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=1,h=nums.size()-2,n=nums.size();
        if(nums.size()==1){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[n-1]>nums[n-2]){
            return n-1;
        }
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }else if(nums[mid+1]>nums[mid]){
                l=mid+1;
            }else if(nums[mid-1]>nums[mid]){
                h=mid-1;
            }
        }
        return -1;
    }
};