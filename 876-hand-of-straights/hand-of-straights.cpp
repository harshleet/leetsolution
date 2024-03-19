class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        map<int,int>m;
        for(int i=0;i<hand.size();i++){
            m[hand[i]]++;
        }
        for(auto it:m){
            pq.push({it.first,it.second});
        }
        if(hand.size()%groupSize!=0){
            return false;
        }
        while(!pq.empty()){
            vector<pair<int,int>>todo;
            todo.push_back(pq.top());
            int last=pq.top().first;
            cout<<last<<endl;
            pq.pop();
            for(int i=1;i<groupSize;i++){
                cout<<pq.top().first<<endl;
                 if(!pq.empty() && pq.top().first-last==1){
                    todo.push_back(pq.top());
                    last=pq.top().first;
                    cout<<last<<endl;
                    pq.pop();
                 }else{
                    return false;
                 }
            }
            for(int i=0;i<todo.size();i++){
               if(todo[i].second>1){
                   pq.push({todo[i].first,todo[i].second-1});
               }
            }
        }
        return true;

    }
};