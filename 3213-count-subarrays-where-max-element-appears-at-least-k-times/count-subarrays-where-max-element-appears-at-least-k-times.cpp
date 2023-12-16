class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        map<int,int>m;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            maxi=max(maxi,nums[i]);
        }
        if(m[maxi]<k){
            return 0;
        }
       long long c=0,j=0;
       long long sb=0;
        for(int i=0;i<nums.size();i++){
              if(nums[i]==maxi){
                  c++;
                 while(c>=k){
                     if(nums[j]==maxi){
                         c--; 
                     }
                      j++;
                     sb+=nums.size()-i;
                 }
              }
        }
        return sb;
    }
};