class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>>adj(n);

        map<vector<int>,int>vis;
        for(auto it:redEdges){
            adj[it[0]].push_back({it[1],1});
            // adj[it[1]].push_back({it[0],1});
        }

        for(auto it:blueEdges){
            adj[it[0]].push_back({it[1],2});
            // adj[it[1]].push_back({it[0],2});
        }
        vector<int>dis(n,1e9);

        queue<vector<int>>q;
        q.push({0,-1,0});
        dis[0]=0;

        while(!q.empty()){
            vector<int>t=q.front();
            q.pop();

            for(auto it:adj[t[0]]){
                if((t[1]==-1 || (t[1]==2 && it.second==1) || (t[1]==1 && it.second==2)) && dis[it.first]>1+t[2] && vis.find({t[0],it.first,it.second})==vis.end()){
                     vis[{t[0],it.first,it.second}]=1;
                    dis[it.first]=1+t[2];
                    q.push({it.first,it.second,1+t[2]});
                }else if(t[1]==-1 || (t[1]==2 && it.second==1) || (t[1]==1 && it.second==2)&& vis.find({t[0],it.first,it.second})==vis.end()){
                     vis[{t[0],it.first,it.second}]=1;
                    q.push({it.first,it.second,1+t[2]});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(dis[i]==1e9){
                dis[i]=-1;
            }
        }

        return dis;
    }
};