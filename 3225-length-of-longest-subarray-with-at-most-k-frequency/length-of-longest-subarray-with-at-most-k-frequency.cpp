class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int j=0,maxi=0;
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            while(m[nums[i]]>k){
               m[nums[j]]--;
               j++;
            }
            maxi=max(maxi,i-j+1);
        }
        return maxi;
    }
};