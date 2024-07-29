class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int mini=INT_MAX,maxi=0,maxii=-1,minii=-1,st=0,i=0;
        long long ans=0;
        while(i<nums.size()){
            if(nums[i]>maxK || nums[i]<minK){
                st=i+1;
                maxi=0;
                mini=INT_MAX;
                i++;
                continue;
            }
            if(nums[i]>=maxi){
                maxi=nums[i];
                maxii=i;
            }


            if(nums[i]<=mini){
                mini=nums[i];
                minii=i;
            }

            if(mini==minK && maxi==maxK){
                ans=(ans+(min(minii,maxii)-st+1));
                // ans=ans+(i-max(minii,maxii)+1);
            }
            i++;
        }
        return ans;
    }
};