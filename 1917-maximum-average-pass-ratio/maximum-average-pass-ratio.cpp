class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>>pq;
        for(int i=0;i<classes.size();i++){
            double delta=((classes[i][0]+1)/(double)(classes[i][1]+1))-(classes[i][0]/(double)classes[i][1]);
            pq.push({delta,i});
        }
        for(int i=0;i<extraStudents;i++){
            int ind=pq.top().second;
            cout<<pq.top().first;
            pq.pop();
            classes[ind][0]++;
            classes[ind][1]++;
            double delta=((classes[ind][0]+1)/(double)(classes[ind][1]+1))-(classes[ind][0]/(double)classes[ind][1]);
            pq.push({delta,ind});
        }
        double ans=0;
        for(int i=0;i<classes.size();i++){
            ans+=(classes[i][0]/(double)classes[i][1]);
        }
        ans/=((double)classes.size());
        return ans;
    }
};