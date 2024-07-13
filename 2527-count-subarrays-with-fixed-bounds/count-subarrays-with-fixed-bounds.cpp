class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long st=0,en=0,ans=0,n=nums.size(),i=0;
        long long mini=INT_MAX,maxi=0,minii=-1,maxii=-1;
        while(i<n){
            if(minK>nums[i] || maxK<nums[i]){
                st=i+1;
                en=i+1;
                mini=INT_MAX;
                maxi=0;
                i++;
                continue;
            }
            if(nums[i]<=mini){
                mini=nums[i];
                minii=i;
            }
            if(nums[i]>=maxi){
                maxi=nums[i];
                maxii=i;
            }
            if(mini==minK && maxi==maxK){
                ans+=min(minii,maxii)-st+1;
            }
            

            i++;
            en=i;
        }
        return ans;
    }
};