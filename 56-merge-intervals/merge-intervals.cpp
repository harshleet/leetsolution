class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it: intervals){
            pq.push({it[0],it[1]});
        }
       vector<vector<int>>ans;
        while(!pq.empty()){
            int st=pq.top().first;
            int en=pq.top().second;
            pq.pop();

            while(!pq.empty() && pq.top().first<=en){
                en=max(en,pq.top().second);
                pq.pop();
            }
            vector<int>temp={st,en};
            ans.push_back(temp);
        }
        return ans;
    }
};