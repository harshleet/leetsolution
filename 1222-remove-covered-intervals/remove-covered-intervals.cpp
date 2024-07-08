class Solution {
public:
   struct cmp{
      bool operator()(const vector<int>&a ,const vector<int>&b){
        if(a[0]!=b[0]){
            return a[0]>b[0];
        }
        return a[1]<b[1];
      }
   };
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        priority_queue<vector<int>,vector<vector<int>>,cmp>pq;

        for(auto it:intervals){
            pq.push(it);
        }

        int c=0;

        while(!pq.empty()){
            int st=pq.top()[0];
            int en=pq.top()[1];
            pq.pop();
            // cout<<st<<" "<<en<<endl;
            while(!pq.empty() && en>=pq.top()[0]){
                if(pq.top()[1]<=en){
                    c++;
                }
                en=max(en,pq.top()[1]);
                pq.pop();
            }
        }
        return intervals.size()-c;
    }
};