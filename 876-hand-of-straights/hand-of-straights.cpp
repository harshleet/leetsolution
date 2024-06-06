class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size()%groupSize!=0) {
            return false;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < hand.size(); i++) {
            pq.push(hand[i]);
        }
        while (!pq.empty()) {
            vector<int> temp;
            int cnt = 0, pre = -1;
            
            while (cnt < groupSize && !pq.empty()) {
                int vl = pq.top();
                pq.pop();
                if (pre == -1 || vl - pre == 1) {
                    cnt++;
                    pre = vl;
                } else if(pre==vl){
                    temp.push_back(vl);
                }else {
                    return false;
                }
            }
            if(cnt!=groupSize){
                return false;
            }
            for(int i=0;i<temp.size();i++){
                cout<<temp[i]<<endl;
                pq.push(temp[i]);
            }
        }
        return true;
    }
};