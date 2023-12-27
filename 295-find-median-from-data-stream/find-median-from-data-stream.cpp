class MedianFinder {
public:
    priority_queue<int>pq;
    priority_queue<int,vector<int>,greater<int>>pq2;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!pq.empty() && num<pq.top()){
            pq.push(num);
        }else{
            pq2.push(num);
        }

        if(pq2.size()>pq.size()){
            pq.push(pq2.top());
            pq2.pop();
        }else if(pq.size()>pq2.size()+1){
             pq2.push(pq.top());
            pq.pop();
        }
    }
    
    double findMedian() {
        if((pq.size()+pq2.size())%2==0){
            return double(pq.top()+pq2.top())/(double)2;
        }else{
            return double(pq.top());
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */