class Solution {
public:
    int atleast(int k,vector<int>&nums){
        int j=0,c=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1){
                c++;
            }
            while(c>=k && j<=i){
                ans+=nums.size()-i;
                if(nums[j]%2==1){
                        c--;
                }
                j++;
            }
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atleast(k,nums)-atleast(k+1,nums);
    }
};