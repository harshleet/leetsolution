class Solution {
public:
     bool isPossible(int mid,vector<int>&nums,int threshold){
         int p=0;
         for(int i=0;i<nums.size();i++){
             p+=ceil(nums[i]/(double)mid);
         }
         return p<=threshold;
     }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(mid,nums,threshold)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};