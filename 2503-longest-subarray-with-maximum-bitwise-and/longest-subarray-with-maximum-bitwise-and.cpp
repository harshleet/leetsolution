class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int cnt=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi){
                cnt++;
            }else{
                cnt=0;
            }
            ans=max(cnt,ans);
        }
        return ans;
    }
};