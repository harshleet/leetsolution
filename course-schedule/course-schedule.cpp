class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
       //BHai adjacency list create kar le 

        vector<int>indegree(V,0);
        
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }//bhai bo course dekh jisme koi pre-req. nhi hai

        queue<int>q;
        for(int i=0;i<V;i++){
                if(indegree[i]==0)
                {
                   q.push(i);
                 }         
        }
        //now traverse it
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        //if you can find them ll than just return true
        if(ans.size()==numCourses)return true;
        return false;
    }
};