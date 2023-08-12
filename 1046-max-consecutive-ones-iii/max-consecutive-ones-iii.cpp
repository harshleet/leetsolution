class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j=0;
        int nzero=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
        
            if(nums[i]==0){
                nzero++;
                while(nzero>k){
                    if(nums[j]==0){
                        nzero--;
                    }
                    j++;
                }

            }
            maxi=max(maxi,i-j+1);

        }
        return maxi;
    }
};