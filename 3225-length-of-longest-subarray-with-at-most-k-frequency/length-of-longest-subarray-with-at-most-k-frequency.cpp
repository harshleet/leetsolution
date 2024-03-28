class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int j=0,i=0,maxi=0;
        map<int,int>m;
       while(i<nums.size()){
            m[nums[i]]++;
            while(m[nums[i]]>k && j<i){
               m[nums[j++]]--;
             
            }
            maxi=max(maxi,i-j+1);
            i++;
        }
        return maxi;
    }
};