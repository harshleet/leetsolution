class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        // int start=1;
        // queue<tuple<int,int,int>>q;
        // q.push({0,maxDoubles,1});
        // vector<int>vis(target+1,0);
        // vis[1]=1;

        // while(!q.empty()){
        //     int dis=get<0>(q.front());
        //     int doub=get<1>(q.front());
        //     int val=get<2>(q.front());
        //     q.pop();
        //      if(val==target){
        //         return dis;
        //      }
        //     if(val+1<=target && !vis[val+1]){
        //         q.push({dis+1,doub,val+1});
        //     }
        //     if(2*val<=target && !vis[2*val] && doub>0){
        //         q.push({dis+1,doub-1,2*val});
        //     }
        // }
        // return -1;
          long long int ans=0;
        while(target!=1){
            if(target%2==0 && maxDoubles>0 && target/2>=1){
                target/=2;
                maxDoubles--;
                ans++;
            }else if(maxDoubles==0){
                ans+=target-1;
                target=1;
            }else{
                target--;
                ans++;
            }
        }
        return ans;
    }
};