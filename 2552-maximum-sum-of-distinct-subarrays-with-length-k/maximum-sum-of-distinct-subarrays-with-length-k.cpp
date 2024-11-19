class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxi=0;
        map<int,int>mp;
        long long cur=0;
        int cnt=0;
        for(int i=0;i<k;i++){
            if(mp[nums[i]]==1){
                cnt++;
            }
            mp[nums[i]]++;
            cur+=nums[i];
        }
        if(cnt==0){
            maxi=max(maxi,cur);
        }
        for(int i=k;i<nums.size();i++){
            mp[nums[i-k]]--;
            cur-=nums[i-k];
            if(mp[nums[i-k]]==1){
                cnt--;
            }
            if(mp[nums[i]]==1){
                cnt++;
            }
            mp[nums[i]]++;
            cur+=nums[i];
            if(cnt==0){
                maxi=max(maxi,cur);
            }
        }
        return maxi;

    }
};