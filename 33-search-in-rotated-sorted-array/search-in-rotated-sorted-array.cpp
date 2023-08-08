class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
       // intution is that left of the right side must be sorted
       while(low<=high){
           int mid=low+(high-low)/2;
           //left part is sorted
           if(nums[mid]==target){
               return mid;
           } 
           if(nums[low]<=nums[mid]){
                 if(nums[low]<=target && nums[mid]>target){
                  high=mid-1;
              }else{
                  low=mid+1;
              }
           }
            else {
              if(target>nums[mid] && nums[high]>=target){
                  low=mid+1;
              }else{
                  high=mid-1;
              }
           }

       } 
      
        return -1;
    }
};
