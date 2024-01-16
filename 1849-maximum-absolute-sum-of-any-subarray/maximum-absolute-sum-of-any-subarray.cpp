class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
       int maxfar=INT_MIN,maxend=0,maxi=0;

       for(int i=0;i<nums.size();i++){
           maxend+=nums[i];
           if(maxfar<maxend){
               maxfar=maxend;
           }
           if(maxend<0){
               maxend=0;
           }
       }
      maxi=max(abs(maxfar),maxi);
      maxfar=0,maxend=0;
      for(int i=0;i<nums.size();i++){
           maxend+=nums[i];
           if(maxfar>maxend){
               maxfar=maxend;
           }
           if(maxend>=0){
               maxend=0;
           }
       }
      maxi=max(abs(maxfar),maxi);
      return maxi;
    }
};