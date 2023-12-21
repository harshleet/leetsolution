class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int s=accumulate(nums.begin(),nums.end(),0);
        int rsum=s-x;
         if(rsum<0){
             return -1;
         }
         if(rsum==0){
             return n;
         }
 
        int j=0;
        int sum=0,maxi=0;
        for(int i=0;i<nums.size();i++){
             sum+=nums[i];
            
             while(sum>rsum){
                 sum-=nums[j];
                 j++;
             }
            if(sum==rsum ){
                  maxi=max(maxi,i-j+1);
            }
        }
        
        if(maxi==0){
            return -1;
        }
        return n-maxi;;
    }
};