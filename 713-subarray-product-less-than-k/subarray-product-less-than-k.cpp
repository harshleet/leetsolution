class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //subrray->slliding window
        if(k==0){
            return 0;
        }
        int j=0,pro=1,ans=0;
        for(int i=0;i<nums.size();i++){
            pro*=nums[i];
            while(pro>=k && j<=i){
                pro/=nums[j];
                j++;
            }
            ans=ans+i-j+1;

        }
        return ans;
    }
};