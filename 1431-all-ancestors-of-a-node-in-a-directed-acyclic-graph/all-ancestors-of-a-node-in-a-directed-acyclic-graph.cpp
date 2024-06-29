class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>ind(n,0);
        map<int,set<int>>mp;
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            ind[it[1]]++;
        }
        queue<int>q;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
                vis[i]=1;
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it:adj[node]){
                ind[it]--;
                if(ind[it]==0){
                    vis[it]=1;
                    if(!mp[node].empty()){
                        mp[it].insert(mp[node].begin(),mp[node].end());
                    }
                     mp[it].insert(node);
                    q.push(it);
                }else if(ind[it]){
                    if(!mp[node].empty()){
                        mp[it].insert(mp[node].begin(),mp[node].end());
                    }
                     mp[it].insert(node);
                }
            }
        }
        vector<vector<int>>ans(n);
        for(auto it:mp){
            // cout<<it.second.size()<<endl;
            ans[it.first]=vector<int>(it.second.begin(),it.second.end());
        }
        return ans;
    }
};