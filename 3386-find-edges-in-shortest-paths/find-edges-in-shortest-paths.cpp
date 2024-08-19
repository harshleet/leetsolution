class Solution {
public:
   
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        vector<vector<pair<int,int>>>adj(n);
      
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
           
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});

        vector<int>dis(n,1e9);
        dis[0]=0;

        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                if(dist+it.second<dis[it.first]){
                    dis[it.first]=dist+it.second;
                    pq.push({dis[it.first],it.first});
                }
            }
        }

        vector<bool>ans(m,false);
        if(dis[n-1]==1e9){
            return ans;
        }
        int val=dis[n-1];

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq2;
        pq2.push({0,n-1});

        vector<int>dis2(n,1e9);
        dis2[n-1]=0;

        while(!pq2.empty()){
            int dist=pq2.top().first;
            int node=pq2.top().second;
            pq2.pop();

            for(auto it:adj[node]){
                if(dist+it.second<dis2[it.first]){
                    dis2[it.first]=dist+it.second;
                    pq2.push({dis2[it.first],it.first});
                }
            }
        }

        for(int i=0;i<m;i++){
            int node1=edges[i][0],node2=edges[i][1];
            if(dis[node1]+dis2[node2]+edges[i][2]==val  ||dis[node2]+dis2[node1]+edges[i][2]==val){
                ans[i]=true;
            }
        }
     
        return ans;
    }
};