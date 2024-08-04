class Solution {
public:
    int helper(vector<vector<int>>&adj,int n){
        vector<int>dist(n,1e9);
        queue<pair<int,int>>q;

        q.push({0,0});
        dist[0]=0;
        while(!q.empty()){
            int node=q.front().first;
            int dis=q.front().second;
            q.pop();

            for(auto it:adj[node]){
                if(dis+1<dist[it]){
                    dist[it]=1+dis;
                    q.push({it,dist[it]});
                }
            }
        }
        return dist[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n);

        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }

        vector<int>ans;
        for(auto it:queries){
            adj[it[0]].push_back(it[1]);
            int val=helper(adj,n);
            ans.push_back(val);
        }
        return ans;
    }
};