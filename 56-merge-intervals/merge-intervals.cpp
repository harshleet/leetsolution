class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int n=intervals.size();
        int i=0;
        for(i=1;i<n;i++){
            vector<int>v;
            int start=intervals[i-1][0];
            int end=intervals[i-1][1];
             while(i< n && end>=intervals[i][0]){
               start=min(start,intervals[i][0]);
               end=max(end,intervals[i][1]);
               i++;
             }
             v.push_back(start);
              v.push_back(end);
              ans.push_back(v);
        }
        cout<<i<<" ";
        if(i==n){
            ans.push_back(intervals[n-1]);
        }
        return ans;
    }
};