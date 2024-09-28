class MyCircularDeque {
public:
    list<int>ls;
    int sz;
    int csz=0;
    MyCircularDeque(int k) {
        sz=k;
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        ls.push_front(value);
        csz++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        ls.push_back(value);
        csz++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        ls.pop_front();
        csz--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        ls.pop_back();
        csz--;
        return true;
    }
    
    int getFront() {
        if(ls.size()==0){
            return -1;
        }
        return ls.front();
    }
    
    int getRear() {
        if(ls.size()==0){
            return -1;
        }
        return ls.back();
    }
    
    bool isEmpty() {
        if(csz==0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(sz==csz){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */