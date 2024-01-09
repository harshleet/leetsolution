class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(y>=x){
            return y-x;
        }
         map<int,int>m;
         queue<pair<int,int>>q;
          q.push({x,0});
        m[x]=1;
        
        while(!q.empty()){
            int node=q.front().first;
            int step=q.front().second;
            q.pop();
            
            if(node==y){
                return step;
            }

            if(node%5==0 && m.find(node/5)==m.end()){
                m[node/5]=1;
                q.push({node/5,step+1});
            }
            if(node%11==0 && m.find(node/11)==m.end()){
                m[node/11]=1;
                q.push({node/11,step+1});
            }
            if(m.find(node-1)==m.end()){
                m[node-1]=1;
                q.push({node-1,step+1});
            }
            if(m.find(node+1)==m.end()){
                m[node+1]=1;
                q.push({node+1,step+1});
            }
        }
        return -1;


    }
};