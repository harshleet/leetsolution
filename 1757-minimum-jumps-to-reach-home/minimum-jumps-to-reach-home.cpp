class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        set<int>forb(forbidden.begin(),forbidden.end());

        vector<int>vis(6001,0);

        queue<vector<int>>q;
        q.push({0,0,0});
        vis[0]=1;

        while(!q.empty()){
            int node=q.front()[0];
            int dis=q.front()[1];
            int bck=q.front()[2];
            q.pop();

            if(node==x){
                return dis;
            }
            if(bck==0 && node-b>=0 && !vis[node-b] && forb.find(node-b)==forb.end()){
                vis[node-b]=1;
                q.push({node-b,dis+1,1});
            }

            if(node+a<=6000 && !vis[x+a] && forb.find(node+a)==forb.end()){
                vis[node+a]=1;
                q.push({node+a,dis+1,0});
            }
        }
        return -1;
    }
};