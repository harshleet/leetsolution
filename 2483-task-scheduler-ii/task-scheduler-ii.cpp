class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        map<long long,long long>last;

        long long timer=0;
        for(int i=0;i<tasks.size();i++){
            timer++;
            if(last.find(tasks[i])!=last.end() && timer-last[tasks[i]]<=space){
                // cout<<i<<" "<<last[tasks[i]]<<endl;
                timer+=(last[tasks[i]]+space-timer+1);
                last[tasks[i]]=timer;
            }else{
                last[tasks[i]]=timer;
            }
        }
        return timer;
    }
};