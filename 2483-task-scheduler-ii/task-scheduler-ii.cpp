class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long timer=1,i=0;
        int n=tasks.size();
        map<long long,long long>last;
        for(long long i=0;i<n;i++){
            cout<<tasks[i]<<" "<<timer<<endl;
            if(last.find(tasks[i])==last.end()){
                last[tasks[i]]=timer;
                if(i!=n-1){
                   timer++;
                } 
            }else if(space+last[tasks[i]]+1<=timer){
               
                last[tasks[i]]=timer;
                 if(i!=n-1){
                   timer++;
                }
            }else if(space+last[tasks[i]]+1>timer){
                timer=space+last[tasks[i]]+1;
                last[tasks[i]]=timer;
                 if(i!=n-1){
                   timer++;
                }
                 
            }
        }
        
        return timer;
    }
};