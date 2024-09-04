class Solution {
public:

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
         int x=0,y=0;
         int d=0;
         int maxi=0;
         set<vector<int>>obs(obstacles.begin(),obstacles.end());
         for(int i=0;i<commands.size();i++){
            if(commands[i]==-1){
                if(d==0){
                    d=1;
                }else if(d==1){
                    d=2;
                }else if(d==2){
                    d=3;
                }else if(d==3){
                    d=0;
                }
            }else if(commands[i]==-2){
                if(d==0){
                    d=3;
                }else if(d==1){
                    d=0;
                }else if(d==2){
                    d=1;
                }else if(d==3){
                    d=2;
                }
            }else{
                int k=commands[i];
                if(d==0){
                    for(int j=0;j<k;j++){
                        if(obs.find({x,y+1})==obs.end()){
                            y++;
                        }else{
                            break;
                        }
                    }    
                }else if(d==1){
                    for(int j=0;j<k;j++){
                        if(obs.find({x+1,y})==obs.end()){
                            x++;
                        }else{
                            break;
                        }
                    } 
                }else if(d==2){
                     for(int j=0;j<k;j++){
                        if(obs.find({x,y-1})==obs.end()){
                            y--;
                        }else{
                            break;
                        }
                    } 
                }else if(d==3){
                     for(int j=0;j<k;j++){
                        if(obs.find({x-1,y})==obs.end()){
                            x--;
                        }else{
                            break;
                        }
                    } 
                }
            }
            int dis=pow(x,2)+pow(y,2);
            maxi=max(maxi,dis);
         }
         return maxi;
    }
};