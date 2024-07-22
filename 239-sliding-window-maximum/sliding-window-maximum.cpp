class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>>dq;
        for(int i=0;i<k;i++){
            if(dq.empty()){
                dq.push_back({nums[i],i});
            }else{
                while(!dq.empty() && dq.back().first<=nums[i]){
                    dq.pop_back();
                }
                dq.push_back({nums[i],i});
            }
        }
        vector<int>ans;
         ans.push_back(dq.front().first);
        for(int i=k;i<nums.size();i++){
              
            if(dq.front().second==i-k){
                dq.pop_front();
            }
            if(dq.empty()){
                dq.push_back({nums[i],i});
            }else{
                while(!dq.empty() && dq.back().first<=nums[i]){
                    dq.pop_back();
                }
                dq.push_back({nums[i],i});
            }
             ans.push_back(dq.front().first);
           
        }
    
        return ans;
    }
};