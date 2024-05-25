class Solution {
public:
    int atleast(int goal,vector<int>&nums){
        int j=0,c=0,ans=0;
        for(int i=0;i<nums.size();i++){
                c+=nums[i];
                while(c>=goal && j<=i){
                    ans+=nums.size()-i;
                    c-=nums[j];
                    j++;
                }
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //exact to nih kar skte we try to find the atleast value
        return atleast(goal,nums)-atleast(goal+1,nums);
    }
};