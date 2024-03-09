class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j=0,sum=0,mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>=target){
                mini=min(mini,i-j+1);
                sum-=nums[j];
                j++;
            }
        }
        if(mini==INT_MAX){
            return 0;
        }
        return mini;
    }
};