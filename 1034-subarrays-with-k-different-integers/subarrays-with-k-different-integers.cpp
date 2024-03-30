class Solution {
public:
    int helper(vector<int>& nums, int k){
        int j=0,ans=0;
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            while(m.size()>=k){
                m[nums[j]]--;
                if(m[nums[j]]==0){
                    m.erase(nums[j]);
                }
                j++;
            }
            ans+=i-j+1;

        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //exactly k
        return helper(nums,k+1)-helper(nums,k);
    }
};