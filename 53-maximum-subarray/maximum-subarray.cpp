class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxfar=INT_MIN,maxend=0;

       for(int i=0;i<nums.size();i++){
           maxend+=nums[i];
           if(maxfar<maxend){
               maxfar=maxend;
           }
           if(maxend<0){
               maxend=0;
           }
       }
       return maxfar;
    }
};