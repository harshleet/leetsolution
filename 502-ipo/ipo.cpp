class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first){
            return b.second<a.second;
        }
        return a.first<b.first;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v;
        for(int i=0;i<profits.size();i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end(),cmp);
        // for(int i=0;i<profits.size();i++){
        //     cout<<v[i].first<<" "<<v[i].second<<endl;
        // }
        int ans=0;
        priority_queue<int>pq;
        int j=0;
        int n=v.size();
        for(int i=0;i<k;i++){
            while(j<n && w>=v[j].first){
                pq.push(v[j].second);
                j++;
            }
            if(!pq.empty()){
                w+=pq.top();
                ans+=pq.top();
                pq.pop();
            }
        }
        return w;
    }
};