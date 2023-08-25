class Solution {
public:
    int check(int mid,vector<int>&nums){
        int st=1;
        long long cur=0;
        for(int i=0;i<nums.size();i++){
            if(cur+nums[i]>mid){
                cur=0;
                st++;
            }
            cur+=nums[i];
        }
        return st;
    }
    int splitArray(vector<int>& nums, int k) {
       if(nums.size()<k){
           return -1;
       }
       int low=*max_element(nums.begin(),nums.end());
       int high=accumulate(nums.begin(),nums.end(),0);
       while(low<=high){
           int mid=(low+high)/2;
           if(check(mid,nums)>k){
               low=mid+1;
           }else{
               high=mid-1;
           }

       }
       return low;
    }
};