class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<meetings.size();i++){
            adj[meetings[i][0]].push_back({meetings[i][1],meetings[i][2]});
            adj[meetings[i][1]].push_back({meetings[i][0],meetings[i][2]});
        }
        set<int>v;
        vector<int>vis(n,0);
       
        priority_queue<pair<int,int>, vector<pair<int,int> > , greater<pair<int,int>>>pq;
        pq.push({0,0});
        pq.push({0,firstPerson});
        
  
       
        while(!pq.empty()){
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(vis[node]==1){
                continue;
            }
            vis[node]=1;
            v.insert(node);
            for(auto it:adj[node]){
                if(time<=it.second){
                    pq.push({it.second,it.first});
                }
                 
            }
        } 
        
        return vector<int>(v.begin(),v.end());
    }
};