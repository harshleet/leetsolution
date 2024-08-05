class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>>pq;
        map<char,int>mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }

        int timer=0;

        while(!pq.empty()){
            if(pq.top().first==1){
                return pq.size()+timer;
            }
            // cout<<"a"<<endl;
             vector<pair<int,char>>temp;
             temp.push_back(pq.top());
            //   cout<<pq.top().second<<endl;
            pq.pop();
           
            timer++;
            for(int i=0;i<n ;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top());
                    //  cout<<pq.top().second<<endl;
                    pq.pop();
                }
                timer++;
            }

            for(int i=0;i<temp.size();i++){
                if(temp[i].first>1){
                    pq.push({temp[i].first-1,temp[i].second});
                }
            }
        }
        return timer;
    }
};