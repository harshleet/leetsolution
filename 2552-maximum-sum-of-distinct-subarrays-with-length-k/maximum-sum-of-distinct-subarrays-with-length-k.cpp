class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
       map<int,int>m;
       long long maxi=0;
       long long  sum=0;
   
       for(int i=0;i<k;i++){
             m[nums[i]]++;
             sum+=nums[i];
       } 
       if(m.size()==k){
           maxi=max(maxi,sum);
       }
       for(int i=k;i<nums.size();i++){
           sum-=nums[i-k];
           m[nums[i-k]]--;
           if(m[nums[i-k]]==0){
               m.erase(nums[i-k]);
           }
           sum+=nums[i];
           m[nums[i]]++;
           if(m.size()==k){
              maxi=max(maxi,sum);
            }
          
       }
       return maxi;
    }
};