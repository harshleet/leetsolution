class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        for(auto it:intervals){
            pq.push(it);
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            int st=pq.top()[0];
            int end=pq.top()[1];
            pq.pop();
            while(!pq.empty() && end>=pq.top()[0]){
                end=max(end,pq.top()[1]);
                pq.pop();
            }
            
            ans.push_back({st,end});
        }
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};