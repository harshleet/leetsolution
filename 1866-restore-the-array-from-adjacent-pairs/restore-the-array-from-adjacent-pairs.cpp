#include <vector>
#include <queue>
#include <map>

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        vector<int> ans;
        map<int,vector<int>> adj;
        map<int,int> in;
       
        for (int i = 0; i < n-1; i++) {
           

            int val1 = adjacentPairs[i][0];
            int val2 = adjacentPairs[i][1];
            cout<<val1<<" "<<val2<<" ";
            adj[val1].push_back(val2);
            adj[val2].push_back(val1);
            in[val1]++;
            in[val2]++;
        }
        

        queue<int> q;
        for (auto it:in) {
            if (it.second == 1) {
                q.push(it.first);
                break;
            }
        }
       map<int,bool>vis;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            vis[node]=true;
            for (auto it : adj[node]) {
                in[it]--;
                if (in[it] == 1 ||(in[it] == 0 && vis[it]==false)) {
                    q.push(it);
                }
            }
        }
        

        return ans;
    }
};
