class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<long long>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        for(int i=0;i<k;i++){
            int val=pq.top();
            ans+=pq.top();
            pq.pop();
            pq.push(ceil(val/3.0));
        }
        return ans;
    }
};