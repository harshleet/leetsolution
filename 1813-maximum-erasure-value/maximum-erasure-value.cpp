class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int j=0;
        int sum=0;
        int maxi=0;
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            sum+=nums[i];
            while(m[nums[i]]>1){
                sum-=nums[j];
                m[nums[j]]--;
                j++;
                
            }
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};