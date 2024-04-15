class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int j=0,sum=0,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
           sum+=nums[i];
           maxi=max(maxi,sum);
           while(sum<0){
               sum=0;
           }
           
        }
        sum=0;
        for(int i=0;i<nums.size();i++){
           sum+=nums[i];
           maxi=max(maxi,abs(sum));
           while(sum>0){
               sum=0;
           }
           
        }
        return maxi;
    }
};