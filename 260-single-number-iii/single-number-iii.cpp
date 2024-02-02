class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int i=0;
        for( i=0;i<nums.size()-1;i++){
            if((nums[i]^nums[i+1])!=0){
                ans.push_back(nums[i]);
            }else{
                i++;
            }
        }
        cout<<i<<" ";
        if (i == nums.size() - 1) {
              ans.push_back(nums[i]);
          }
        
        return ans;
    }
};