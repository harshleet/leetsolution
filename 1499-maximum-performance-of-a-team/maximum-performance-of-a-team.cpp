class Solution {
public:
int mod=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
         priority_queue<pair<long long,long long>>pq;
         for(int i=0;i<n;i++){
             pq.push({efficiency[i],speed[i]});
         }
         vector<pair<long long,long long>>v;
         while(!pq.empty()){
             int eff=pq.top().first;
             int see=pq.top().second;
             pq.pop();
             v.push_back({eff,see});
         }
        
         long long sum=0,eff=INT_MAX;
         long long maxi=0;
         priority_queue<long long, vector<long long>, greater<long long>> pq1;
         for(int i=0;i<k;i++){
               eff=min(v[i].first,eff);
               pq1.push(v[i].second);
               sum+=v[i].second;
              maxi=max(maxi,(sum*eff));
         }
         for(int i=k;i<n;i++){
             maxi=max(maxi,(sum*eff));
             eff=min(v[i].first,eff);
             if(!pq1.empty()){
                 sum-=pq1.top();
                 pq1.pop();
             }
             sum+=v[i].second;
             pq1.push(v[i].second);
         }
         maxi=max(maxi,(sum*eff));
    return maxi%mod;
    }
};