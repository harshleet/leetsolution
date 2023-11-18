class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
       long long maxi=0;
        long long j=0;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
                sum+=nums[i]; 
                while( (i-j+1)*nums[i]-sum>k){
                    sum-=nums[j];
                    j++;
                }
            maxi=max(maxi,i-j+1);
        }
        return maxi;
    }
};