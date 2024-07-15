class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<hand.size();i++){
            pq.push(hand[i]);
        }

        while(!pq.empty()){
            int prev=-1,sz=0;
            vector<int>temp;
            while(!pq.empty() && sz<groupSize){
                int val=pq.top();
                pq.pop();
                // cout<<val<<" ";
                if(prev==-1 || val==prev+1){
                    prev=val;
                    sz++;
                }else if(prev==val){
                    temp.push_back(val);
                }else{
                    return false;
                }
            }
            if(sz!=groupSize){
                return false;
            }
            for(int i=0;i<temp.size();i++){
                pq.push(temp[i]);
            }
        }
        return true;
    }
};