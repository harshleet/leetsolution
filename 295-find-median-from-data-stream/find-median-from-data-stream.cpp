class MedianFinder {
public:
    priority_queue<int>pq1;
    priority_queue<int,vector<int>,greater<int>>pq2;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq2.size()<pq1.size()){
            pq2.push(num);
        }else{
            pq1.push(num);
        }
        if(!pq1.empty() && !pq2.empty() && pq1.top()>pq2.top()){
            int vl=pq1.top();
            pq1.pop();
            pq1.push(pq2.top());
            pq2.pop();
            pq2.push(vl);
        }
    }
    
    double findMedian() {
        if(pq1.size()==pq2.size()){
            double vl=double(pq1.top()+pq2.top())/2;
            // double v2=double()
            return vl;
        }else{
            return double(pq1.top());
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */