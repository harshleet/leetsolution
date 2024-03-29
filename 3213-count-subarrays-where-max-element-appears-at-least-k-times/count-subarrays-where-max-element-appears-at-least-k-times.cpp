class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long j=0;
        long long maxi=*max_element(nums.begin(),nums.end());
        long long ans=0;
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
                 m[nums[i]]++;
                 while( m[maxi]>=k && j<=i){
                    ans+=(nums.size()-i);
                     m[nums[j]]--;
                     j++;
                 }
        }
        return ans;
    }
};