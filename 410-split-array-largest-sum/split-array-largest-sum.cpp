class Solution {
public:
    bool isPos(int mid,vector<int>&nums,int k){
        int p=0,sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }else if(nums[i]<=mid){
                sum=nums[i];
                p++;
            }else{
                return false;
            }
        }
        if(sum>0){
            p++;
        }
        return p<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=0,h=accumulate(nums.begin(),nums.end(),0);
         int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;

            if(isPos(mid,nums,k)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};