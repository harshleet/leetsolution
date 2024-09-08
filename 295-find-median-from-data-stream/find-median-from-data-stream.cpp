class MedianFinder {
public:
    priority_queue<int>pq1;
    priority_queue<int,vector<int>,greater<int>>pq2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq1.empty()){
            pq1.push(num);
        }else if(pq1.size()>pq2.size()){
            if(num>=pq1.top()){
                pq2.push(num);
            }else{
                int val=pq1.top();
                pq1.pop();
                pq1.push(num);
                pq2.push(val);
            }
        }else if(pq1.size()==pq2.size()){
            if(num<=pq2.top()){
                pq1.push(num);
            }else{
                int val=pq2.top();
                pq2.pop();
                pq1.push(val);
                pq2.push(num);
            }
        }
    }
    
    double findMedian() {
        if(pq1.size()==pq2.size()){
            return (pq1.top()+pq2.top())/2.0;
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