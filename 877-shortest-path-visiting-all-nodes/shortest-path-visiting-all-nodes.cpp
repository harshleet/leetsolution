class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();

        map<pair<int,int>,int>seen;

        queue<tuple<int,int,int>>q;
        for(int i=0;i<n;i++){
            q.push({i,1<<i,0});
           seen[{i,1<<i}]=1;
        }
        
        while(!q.empty()){
            int node=get<0>(q.front());
            int bitm=get<1>(q.front());
            int step=get<2>(q.front());
            q.pop();
            // cout<<node<<" "<<bitm<<" "<<step<<endl;
           
            if(bitm==(1<<n)-1){
                return step;
            }
           
           
            for(auto it:graph[node]){
                if(seen.find({bitm|1<<it,it})==seen.end()){
                     seen[{bitm|1<<it,it}]=1;
                q.push({it,bitm|1<<it,step+1});
                }
            }


        }
       return 0;
    }
};