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
        while(!pq.empty()){
          if(pq.top().first==1){
            timer+=pq.size();
            break;
          }
            vector<pair<int,char>>left;
             cout<<pq.top().second<<" "<<timer<<endl;
            left.push_back(pq.top());
            pq.pop();
            timer++;
           
            for(int i=0;i<n;i++){
                 if(!pq.empty()){
                   left.push_back(pq.top());
                    pq.pop();  
                   
                }
                 timer++;
            }
            for(int i=0;i<left.size();i++){
                if(left[i].first>1){
                    pq.push({left[i].first-1,left[i].second});
                } 
            }
        }
        return timer;
    }
};