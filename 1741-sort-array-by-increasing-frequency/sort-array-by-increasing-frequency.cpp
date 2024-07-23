class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>frq(201,0);
        for(int i=0;i<nums.size();i++){
            frq[nums[i]+100]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<=200;i++){
            pq.push({frq[i],-i});
        }
        vector<int>ans;
        while(!pq.empty()){
            int fq=pq.top().first;
            int val=pq.top().second;

            pq.pop();

            for(int i=0;i<fq;i++){
                ans.push_back(-(val)-100);
            }
        }
        return ans;
    }
};