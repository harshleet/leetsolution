class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int j=0,maxi=0;
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            while(((m.rbegin())->first-(m.begin())->first)>limit && j<=i){
                m[nums[j]]--;
                if(m[nums[j]]==0){
                    m.erase(nums[j]);
                }
                j++;
            }
            maxi=max(maxi,i-j+1);
        }
        return maxi;
    }
};