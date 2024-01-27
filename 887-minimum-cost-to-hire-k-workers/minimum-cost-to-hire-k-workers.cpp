class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
          priority_queue<pair<double,long long>,vector<pair<double,long long>>,greater<pair<double,long long>>>pq;
         int n=quality.size();
         for(int i=0;i<n;i++){
             pq.push({double(wage[i]/double(quality[i])),quality[i]});
         }
         vector<pair<double,long long>>v;
         while(!pq.empty()){
            double wa=pq.top().first;
            long long qua=pq.top().second;
             cout<<wa<<" "<<qua<<endl;
             pq.pop();
             v.push_back({wa,qua});
         }
        
         long long sum=0;
         double eff=0.0;
         double mini=1000000000.0;
         priority_queue<long long> pq1;
         for(int i=0;i<k;i++){
               eff=max(v[i].first,eff);
               pq1.push(v[i].second);
               sum+=v[i].second;

         }
         for(int i=k;i<n;i++){
            
             mini=min(mini,(sum*eff));
             eff=max(v[i].first,eff);
             if(!pq1.empty()){
                 sum-=pq1.top();
                 pq1.pop();
             }
             sum+=v[i].second;
             pq1.push(v[i].second);
         }
          mini=min(mini,(sum*eff));
         return mini;
    }
};