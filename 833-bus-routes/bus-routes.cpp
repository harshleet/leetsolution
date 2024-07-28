class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        map<int,vector<int>>adj;

        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                adj[routes[i][j]].push_back(i);
            }
        }

        map<int,int>vis;
        map<int,int>bus;
        queue<pair<int,int>>q;
        q.push({source,0});
        vis[source]=1;

        while(!q.empty()){
            int node=q.front().first;
            int dis=q.front().second;
    
            q.pop();

            if(node==target){
                return dis;
            }
            for(auto it:adj[node]){
                if(bus.find(it)==bus.end()){
                    bus[it]=1;
                for(int i=0;i<routes[it].size();i++){

                    if(vis.find(routes[it][i])==vis.end()){
                        vis[routes[it][i]]=1;
                        q.push({routes[it][i],dis+1});
                    }
                }}
            }
        }
        return -1;
    }
};