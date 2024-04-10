class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        vector<int>temp(n,-1);
        queue<int>q;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(deck[i]);
            q.push(i);
        }
        int i=0,c=deck.size();
        int ro=1;
        while(q.size()!=0){
            cout<<q.front()<<" ";
            temp[q.front()]=pq.top();
            pq.pop();
            q.pop();
            if(q.size()>0){
                int sec=q.front();
                q.pop();
                q.push(sec);
            }
           
        }
        return temp;
    }
};