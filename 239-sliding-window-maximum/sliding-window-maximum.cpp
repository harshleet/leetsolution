class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>>dq;
        for(int i=0;i<k;i++){
            if(dq.empty() || dq.front().first>nums[i]){
                dq.push_front({nums[i],i});
            }else{
                while(!dq.empty()&& dq.front().first<=nums[i]){
                    dq.pop_front();
                }
                dq.push_front({nums[i],i});
            }
        }
        vector<int>ans;
        ans.push_back(dq.back().first);
        for(int i=k;i<nums.size();i++){
            if(dq.back().second==i-k){
                dq.pop_back();
            }
            if(dq.empty() || dq.front().first>nums[i]){
                dq.push_front({nums[i],i});
            }else{
                while(!dq.empty()&& dq.front().first<=nums[i]){
                    dq.pop_front();
                }
                dq.push_front({nums[i],i});
            }
            ans.push_back(dq.back().first);
        }
        return ans;
    }
};