class Solution {
public:
  
    long long maximumSubarraySum(vector<int>& nums, int k) {
       int j=0;
        long long maxi=LLONG_MIN;
        vector<long long>pre(nums.size()+1);
        pre[0]=0;
        for(int i=1;i<=nums.size();i++){
            pre[i]=pre[i-1]+nums[i-1];
        }
        map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++){
           m[nums[i]].push_back(i);

           if(m.find((nums[i]-k))!=m.end() ){
               for(auto it:m[(nums[i]-k)]){
                   maxi=max(maxi,pre[i+1]-pre[it]);
               }
               
           }
           if(m.find((nums[i]+k))!=m.end() ){
               for(auto it:m[(nums[i]+k)]){
                   maxi=max(maxi,pre[i+1]-pre[it]);
               }
           }
        }
        if(maxi==LLONG_MIN){
            return 0;
        }
        return maxi;
    }
};