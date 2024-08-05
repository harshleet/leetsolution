class Solution {
public:
   bool isPos(vector<int>&nums,int k,int mid){
    int sum=0;
    int cnt=1;
    for(int i=0;i<nums.size();i++){
        if(sum+nums[i]<=mid){
            sum+=nums[i];
        }else{
            cnt++;
            sum=nums[i];
        }
    }
    return cnt<=k;
   }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end()),h=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;

            if(isPos(nums,k,mid)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};