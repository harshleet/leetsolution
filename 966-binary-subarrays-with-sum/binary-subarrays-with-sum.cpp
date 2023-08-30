class Solution {
public:
    int atmost(vector<int>&nums,int k){
        int j=0,sum=0,size=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(j<=i && sum>k){
                sum-=nums[j];
                j++;
            }
            size+=(i-j+1);
        }
            return size;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};