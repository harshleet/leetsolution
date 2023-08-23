class Solution {
public:
bool isPossible(int mid,vector<int>&nums,int threshold){
    int cnt=0;
    for(int i=0;i<nums.size();i++){
        cnt+=ceil(nums[i]/(double)mid);
    }
    return (cnt<=threshold);
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int low=1;
        int high=nums.back();
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(mid,nums,threshold)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};