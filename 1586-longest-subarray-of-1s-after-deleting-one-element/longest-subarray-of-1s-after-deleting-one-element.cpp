class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int j=0;
        int z=0;
        int maxi=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){

            if(nums[i]==0){
                z++;
            }else{
                cnt++;
            }
            while(z>1 && j<i){
                if(nums[j]==0){
                    z--;
                }else{
                    cnt--;
                }
                j++;
            }
          
            maxi=max(maxi,i-j+1);
            
           
        }
        return maxi-1;
    }
};