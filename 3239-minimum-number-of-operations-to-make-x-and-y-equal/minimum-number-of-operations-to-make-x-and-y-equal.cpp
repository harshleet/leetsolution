class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {

        if(y>=x){
            return y-x;
        }
        queue<pair<int,int>>q;
        q.push({x,0});

        map<int,int>vis;

        vis[x]=1;

        while(!q.empty()){
            int val=q.front().first;
            int st=q.front().second;
            q.pop();

            if(val==y){
                return st;
            }
            
            if(val>x+11){
                continue;
            }

            if(val%11==0 && vis.find(val/11)==vis.end()){
                q.push({val/11,st+1});
                vis[val/11]=1;
            }
            if(val%5==0 && vis.find(val/5)==vis.end()){
                q.push({val/5,st+1});
                vis[val/5]=1;
            }
            if(vis.find(val-1)==vis.end()){
                q.push({val-1,st+1});
                vis[val-1]=1;
            }
            if(vis.find(val+1)==vis.end()){
                q.push({val+1,st+1});
                vis[val+1]=1;
            }
        }
        return -1;
    }
};