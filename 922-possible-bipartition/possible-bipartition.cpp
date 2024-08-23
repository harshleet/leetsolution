class Solution {
public:

    bool bfs(int node,vector<vector<int>>&adj,vector<int>&col){
        queue<pair<int,int>>q;
        q.push({node,0});
        col[node]=0;

        while(!q.empty()){
            int n=q.front().first;
            int c=q.front().second;
            q.pop();

            for(auto it:adj[n]){
                if(col[it]==-1){
                    col[it]=abs(1-c);
                    q.push({it,abs(1-c)});
                }else if(col[it]!=abs(1-c)){
                    // cout<<it<<" "<<col[it]<<" "<<n<<
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>>adj(n);

        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
            adj[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
        }
        queue<int>q;
        vector<int>col(n,-1);
        bool ans=true;
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                ans&=bfs(i,adj,col);
            }
            cout<<col[i]<<endl;
        }

        return ans;
    }
};