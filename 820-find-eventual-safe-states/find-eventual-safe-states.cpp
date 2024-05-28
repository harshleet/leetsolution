class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //for eventual we must check it must lead to cycle and not be aprt of thge cycle
          int n=graph.size();
         vector<vector<int>>adj(n);
         vector<int>in(n,0);
         set<int>ans;
         for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
                in[i]++;
            }
         }

         queue<int>q;
         for(int i=0;i<n;i++){
            if(in[i]==0){
                ans.insert(i);
                q.push(i);
            }
         }

         while(!q.empty()){
            int node=q.front();
            q.pop();

            ans.insert(node);
            for(auto it:adj[node]){
                in[it]--;
                if(in[it]==0){
                    q.push(it);
                }
            }

         }
        return vector<int>(ans.begin(),ans.end());
        
    }
};