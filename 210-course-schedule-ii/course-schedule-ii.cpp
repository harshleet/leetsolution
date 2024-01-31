class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
       vector<int>ind(numCourses,0);
       for(int i=0;i<prerequisites.size();i++){
           adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
           ind[prerequisites[i][1]]++;
       } 
       vector<int>ans;
       queue<int>q;
       vector<int>vis(numCourses,0);
       for(int i=0;i<numCourses;i++){
           if(ind[i]==0){
               q.push(i);
           }
       }
       while(!q.empty()){
           int node=q.front();
           ans.push_back(node);
           vis[node]=1;
           q.pop();
           for(auto it:adj[node]){
               ind[it]--;
               if(ind[it]==0){
                   q.push(it);
               }
           }

       }
       for(int i=0;i<numCourses;i++){
           if(vis[i]==0){
                return {};
           }
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};