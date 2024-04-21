class Solution {
public:
    
    void dfs(int node,int dis,vector<int>&vis,vector<bool>&ans,vector<vector<pair<int,int>>>& adj,int n,int sh,vector<bool>&temp,map<pair<int,int>,int>&m){
        
        if(node==n-1){
            
            if(dis==sh){
                for(int i=0;i<ans.size();i++){
               
                    ans[i]=ans[i]||temp[i];
                }
               
               
            }
            return;
        }
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it.first] && dis+it.second<=sh){
                temp[m[{node,it.first}]]=true;
                dfs(it.first,dis+it.second,vis,ans,adj,n,sh,temp,m);
                temp[m[{node,it.first}]]=false;
            }
        }
        vis[node]=0;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
      
        vector<vector<pair<int,int>>>adj(n);
        map<pair<int,int>,int>m;
        int i=0;
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
            m[{it[0],it[1]}]=i;
            m[{it[1],it[0]}]=i;
            i++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty()){
            int n=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            for(auto it:adj[n]){
                if(dis+it.second<dist[it.first]){
                    dist[it.first]=dis+it.second;
                    pq.push({dis+it.second,it.first});
                }
            }
        }
        int sh=dist[n-1];
     
        vector<bool>ans(edges.size(),false);
        vector<bool>temp(edges.size(),false);
        vector<int>vis(n,0);
        dfs(0,0,vis,ans,adj,n,sh,temp,m);
        return ans;
    }
};