class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int>m;
        for(int i=0;i<tasks.size();i++){
            m[tasks[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:m){
            pq.push({it.second,it.first});
        }
        int timer=0;
        int maxi=0;
        vector<int>time(26,0);
        while(!pq.empty()){
            if(pq.top().first==1){
              timer+=pq.size();
               break;
           }
            char task=pq.top().second;
            int freq=pq.top().first;
            vector<pair<int,char>>todo;
            todo.push_back(pq.top());
             pq.pop();
            timer++;
            for(int i=0;i<n;i++){
               if(!pq.empty()){
                   todo.push_back(pq.top());
                   pq.pop();
               }
               timer++;
            }
            for(int i=0;i<todo.size();i++){
                cout<<todo[i].first<<" "<<todo[i].second<<endl;
                if(todo[i].first>1){
                    pq.push({todo[i].first-1,todo[i].second});
                }
            }
            
        }
        return timer;
    }
};