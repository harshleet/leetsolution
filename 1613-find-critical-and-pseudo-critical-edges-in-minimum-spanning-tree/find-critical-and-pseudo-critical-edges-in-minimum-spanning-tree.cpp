class Solution {
public:
    int helper(vector<vector<pair<int,int>>>&adj,vector<vector<int>>&edges,int n,int ignored,int take){
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>pq;
        int ans=0;
        vector<int>vis(n);

        if(take!=-1){
            pq.push({0,edges[take][0]});
            pq.push({0,edges[take][1]});
            ans+=edges[take][2];
            ignored=take;
        }else{
            pq.push({0,0});
        }


        while(!pq.empty()){
            int len=pq.top()[0];
            int node=pq.top()[1];
            pq.pop();

            if(vis[node]==1){
                continue;
            }
            vis[node]=1;
            ans+=len;
            for(auto it:adj[node]){
                if(!vis[it.first] && it.second!=ignored){
                    
                    pq.push({edges[it.second][2],it.first});
                }
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i])return 1e8;
        }
        return ans;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],i});
            adj[edges[i][1]].push_back({edges[i][0],i});
        }
        vector<int>cr,pcr;
        // do mst to get the min value
        int val=helper(adj,edges,n,-1,-1);

        vector<int>taken(edges.size());
        // lets bro try for each edges check its criticality
        for(int i=0;i<edges.size();i++){
            int temp=helper(adj,edges,n,i,-1);
            if(temp>val){
                taken[i]=1;
                cr.push_back(i);
            }
        }
        // now for the presudeo critical we will force thate dge instaed
        for(int i=0;i<edges.size();i++){
            int temp=helper(adj,edges,n,-1,i);
            if(temp==val && taken[i]==0){
                pcr.push_back(i);
            }
        }

        return {cr,pcr};
    }
};