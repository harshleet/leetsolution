class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<int>ans;
        for(int i=0;i<nums.size();i++){
            if(i+(nums.size()/3)<nums.size() && nums[i]==nums[(nums.size()/3)+i]){
                ans.insert(nums[i]);
            }
        }
        return vector<int>(ans.begin(),ans.end());
    }
};