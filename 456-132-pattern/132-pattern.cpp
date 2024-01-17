class Solution {
public:
    bool find132pattern(vector<int>& nums) {
         stack<pair<int,int>>st1;
         int n=nums.size();
         vector<int>mini(n);
         int minii=INT_MAX;
         for(int i=0;i<n;i++){
           mini[i]=minii;
           minii=min(minii,nums[i]);
         }
         int third=INT_MIN;
         for(int i=0;i<n;i++){
             if(nums[n-1-i]<third){
                 return true;
             }
              while(!st1.empty() && st1.top().first<nums[n-1-i]){
                  third=st1.top().first;
                  
                  st1.pop();
              }
               
            
              st1.push({nums[n-1-i],n-1-i});
         }
         return false;
    }
};