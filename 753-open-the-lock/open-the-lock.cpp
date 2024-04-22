class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string>de(deadends.begin(),deadends.end());
        map<string,int>vis;

        vector<char>cha={'0','1','2','3','4','5','6','7','8','9'};
        queue<pair<string,int>>q;
        if(de.find("0000")!=de.end() ){
                            return -1;
          } 
        vis["0000"]=1;
        q.push({"0000",0});
        while(!q.empty()){
           string node=q.front().first;
           int st=q.front().second;
            q.pop();
              if(node == target){
                return st;
              }
            for(int i=0;i<4;i++){

                for(int move=-1;move<=1;move++){
                    string prev=node;
                    int vl=prev[i]-'0';
                    prev[i]=cha[(10+vl+move)%10];
                        if(de.find(prev)==de.end() && vis.find(prev)==vis.end()){
                            vis[prev]=1;
                            q.push({prev,st+abs(move)});
                        } 
                }
                
            }
        }
        return -1;
    }
};