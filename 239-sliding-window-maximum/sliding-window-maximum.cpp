class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int>m;
        vector<int>ans;
        for(int i=0;i<k;i++){
            m[nums[i]]++;
        }
        ans.push_back((--m.end())->first);
        for(int i=k;i<nums.size();i++){
            m[nums[i-k]]--;
            if(m[nums[i-k]]==0){
                m.erase(nums[i-k]);
            }
            m[nums[i]]++;
              ans.push_back((--m.end())->first);
        }
        return ans;
    }
};