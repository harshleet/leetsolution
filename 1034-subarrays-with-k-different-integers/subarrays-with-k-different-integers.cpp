class Solution {
public:
    int atmostk(vector<int>& nums, int k){
         map<int,int>m;
        int j=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            while(m.size()>k && j<=i){
                m[nums[j]]--;
                if(m[nums[j]]==0){
                    m.erase(nums[j]);
                }
                j++;
            }
                cnt+=i-j+1;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostk(nums,k)-atmostk(nums,k-1);
    }
};