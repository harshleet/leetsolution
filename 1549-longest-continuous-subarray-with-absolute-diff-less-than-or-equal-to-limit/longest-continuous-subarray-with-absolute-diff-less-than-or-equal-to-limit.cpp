class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int j=0;
        map<int,int>m;
       int maxi=0;
        for(int i=0;i<nums.size();i++){
               m[nums[i]]++;
              if(abs(m.begin()->first-m.rbegin()->first)<=limit ){
                maxi=max(maxi,i-j+1);
              }
             else{ 
                 while(abs(m.begin()->first-m.rbegin()->first)>limit){
                 m[nums[j]]--;
                 if(m[nums[j]]==0){
                     m.erase(nums[j]);
                 }
                 j++;
              }
              }
        }
        return maxi;
    }
};