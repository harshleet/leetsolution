class Solution {
public:
    
    // int dfs(int src,int tar,int bus,map<int,int>&vis,map<int,vector<pair<int,int>>>&adj){
    //     if(src==tar){
    //         return 0;
    //     }
    //     vis[src]=1;
    //     int mini=1e8;
    //     for(auto it:adj[src]){
            
    //         if(bus!=it.second && !vis[it.first]){
    //             mini=min(mini,1+dfs(it.first,tar,it.second,vis,adj));
    //         }else if(bus==it.second && !vis[it.first]){
    //             mini=min(mini,dfs(it.first,tar,bus,vis,adj));
    //         }
    //     }
    //      vis[src]=0;
    //     return mini;

    // }
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        map<int,vector<int>>adj;
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                  adj[routes[i][j]].push_back(i);
            }
        //    adj[routes[i][routes[i].size()-1]].push_back({routes[i][0],i});
        }
         map<int,int>vis;
       
        queue<pair<int,int>>q;
        q.push({0,source});
        vis[source]=1;
        vector<bool>bus(routes.size(),false);
        while(!q.empty()){
            int node=q.front().second;
            int dis=q.front().first;
            q.pop();
           
           if(node==target){
            return dis;
           }
            for(auto it:adj[node]){
                if(bus[it]==false){
                    bus[it]=true;
               
                for(int i=0;i<routes[it].size();i++){
                    // cout<<routes[it][i]<<" ";
                    if(vis.find(routes[it][i])==vis.end()){
                        vis[routes[it][i]]=1; 
                        q.push({dis+1,routes[it][i]});
                    }
                }
                 }
            }
        }
        return -1;
    }
};