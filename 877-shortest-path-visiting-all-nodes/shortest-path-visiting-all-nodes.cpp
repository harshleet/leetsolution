class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        //important point here is tahtwe can go to any point again and again
        //number of nodes are also less whicvh are 12 sop we can use store the visited in binary

        int n=graph.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }
        queue<tuple<int,int,int>>q;
        map<pair<int,int>,int>mp;
        for(int i=0;i<n;i++){
            q.push({i,1<<i,0});
            mp[{i,1<<i}]=1;
        }

        
        while(!q.empty()){

            int node=get<0>(q.front());
            int bitm=get<1>(q.front());
            int st=get<2>(q.front());
            q.pop();

            if(bitm==(1<<n)-1){
                return st;
            }

            for(auto it:adj[node]){
                if(mp.find({it,bitm|1<<it})==mp.end()){
                    mp[{it,bitm|1<<it}]=1;
                    q.push({it,bitm|1<<it,st+1});
                }
            }
        }
        return 1;
    }
};