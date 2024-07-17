class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        sort(nums.begin(),nums.end());
        set<vector<int>>st;

        for(int low=0;low<nums.size()-2;low++){
            int middle=low+1;
            int high=nums.size()-1;
            while(middle<high){
                if(nums[low]+nums[middle]+nums[high]>0 ){
                    high--;
                }else if(nums[low]+nums[middle]+nums[high]<0 ){
                    middle++;
                }else{
                    st.insert({nums[low],nums[middle],nums[high]});
                    middle++;
                    high--;
                } 
            }
        }

        return vector<vector<int>>(st.begin(),st.end());
    }
};