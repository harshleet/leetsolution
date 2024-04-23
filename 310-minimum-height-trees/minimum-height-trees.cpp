#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bfs(int no, vector<int> adj[], int& n) {
        queue<pair<int, int>> q;
        vector<int> vis(n,0); 
        q.push({no, 0});
        vis[no] = 1;
        int maxi=0;
        while (!q.empty()) {
            int node = q.front().first;
            int lev = q.front().second;
            maxi= max(maxi, lev);
            q.pop();

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    q.push({it, lev + 1});
                    vis[it] = 1;
                }
            }
        }
        return maxi;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ind(n);
        vector<int> adj[n];
        if(n==1){
            return {0};
        }
        if(n==2){
            return {0,1};
        }
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            ind[edges[i][0]]++;
            ind[edges[i][1]]++;
        }
        
         queue<int>q;
         for(int i=0;i<n;i++){
            if(ind[i]==1){
                q.push(i);
                ind[i]--;
            }
         }
         vector<int>ans;
         
         while(!q.empty()){
             ans.clear();
             int s=q.size();
            for(int i=0;i<s;i++){
                int node=q.front();
                q.pop();
                ans.push_back(node);
                for(auto it:adj[node]){
                    ind[it]--;
                    if(ind[it]==1){
                        q.push(it);
                    }
                }
           }
          
         }
        //  while(!q.empty()){
        //     ans.push_back(q.front());
        //     q.pop();
        //  }
          return ans;
    }
};