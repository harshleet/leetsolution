class Solution {
public:
bool check(int mid,int p,vector<int>&nums){
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i+1]-nums[i]<=mid){
            p--;
            i++;
        }
    }
    if(p<=0){
        return true;
    }
    return false;
}
    int minimizeMax(vector<int>& nums, int p) {
       sort(nums.begin(),nums.end());
       vector<int>dif(nums.size());
        int low=0,high=nums.back()-nums[0];

        while(low<high){
            int mid=(low+high)/2;
            if(check(mid,p,nums)){
       
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};