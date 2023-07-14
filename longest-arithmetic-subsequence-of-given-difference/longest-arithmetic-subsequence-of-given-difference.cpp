class Solution {
public:

    int longestSubsequence(vector<int>& nums, int difference) {
        unordered_map<int,int>m;
        int maxi=1;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]-difference)!=m.end()){
                m[nums[i]]=1+m[nums[i]-difference];
            }else{
                m[nums[i]]=1;
            }
            maxi=max(maxi,m[nums[i]]);
        }
        return maxi;

    }
};