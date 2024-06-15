class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>>pq;
        map<char,int>m;
        for(int i=0;i<tasks.size();i++){
            m[tasks[i]]++;
        }
        for(auto it:m){
            pq.push({it.second,it.first});
        }
        int ans=0;

        while(!pq.empty()){
            if(pq.top().first==1){
                return ans+pq.size();
            }
            vector<pair<int,char>>temp;
            temp.push_back(pq.top());
            pq.pop();
            ans++;
            for(int i=0;i<n && !pq.empty();i++){
               temp.push_back(pq.top());
               pq.pop();
            }
            ans+=n;
            for(int i=0;i<temp.size();i++){
                cout<<temp[i].first<<" "<<ans<<endl;
                if(temp[i].first>1){
                   pq.push({temp[i].first-1,temp[i].second});
                }
            }
        }
        return ans;
    }
};