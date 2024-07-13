class Solution {
public:
    int helper(vector<int>&nums,int vl){
        map<int,int>mp;
        int maxi=0,ans=0,j=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            maxi=(--mp.end())->first;
            while(maxi>vl && j<=i){
                ans+=nums.size()-i;
                mp[nums[j]]--;
                if(mp[nums[j]]==0){
                    mp.erase(nums[j]);
                }
                j++;
                if(!mp.empty()){
                   maxi=(--mp.end())->first;
                }else{
                    maxi=0;
                }
            }
        }
        return ans;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        //number of subarry atleast
        return helper(nums,left-1)-helper(nums,right);
    }
};