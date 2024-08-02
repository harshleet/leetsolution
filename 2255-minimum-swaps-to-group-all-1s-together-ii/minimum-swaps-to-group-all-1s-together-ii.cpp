class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                k++;
            }
        }

        for(int i=0;i<k-1;i++){
            nums.push_back(nums[i]);
        }
        int mini=INT_MAX;
        int cnt=0;
        for(int i=0;i<k;i++){
            if(nums[i]==1){
                cnt++;
            }
        }
        mini=min(mini,k-cnt);
        for(int i=k;i<nums.size();i++){
            if(nums[i-k]==1){
                cnt--;
            }
            if(nums[i]==1){
                cnt++;
            }
            mini=min(mini,k-cnt);
        }
        return mini;
    }
};