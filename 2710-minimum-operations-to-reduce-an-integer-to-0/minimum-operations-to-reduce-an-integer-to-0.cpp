class Solution {
public:
int nobit(int n){
    int cnt=0;
    while(n>0){
        cnt++;
        n/=2;
    }
    return cnt;
}
    int minOperations(int n) {
       queue<pair<int,int>>q;
       map<int,int>m;
       m[n]=1;
       q.push({n,0});

       while(!q.empty()){
          int val=q.front().first;
           int step=q.front().second;
           q.pop();
           if(val==0){
            return step;
           }
            int nbit=nobit(val);
          
              for(int i=0;i<nbit;i++){
                if(val+pow(2,i)<=100000 &&m.find(val+pow(2,i))==m.end()){
                    m[val+pow(2,i)]=1;
                    q.push({val+pow(2,i),step+1});
                }
            }
            for(int i=0;i<nbit;i++){
                if(val-pow(2,i)>=0 && m.find(val-pow(2,i))==m.end()){
                    m[val-pow(2,i)]=1;
                    q.push({val-pow(2,i),step+1});
                }
            }
          

       }
       return -1;
    }
};