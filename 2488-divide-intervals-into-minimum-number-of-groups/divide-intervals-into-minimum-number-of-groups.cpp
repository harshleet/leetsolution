class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<int,vector<int>,greater<int>>temp;
        int cur=0;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
           if(!temp.empty() && intervals[i][0]>temp.top()){
             temp.pop();
           }
            temp.push(intervals[i][1]);
        }
        return temp.size();
    }
};