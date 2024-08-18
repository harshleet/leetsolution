class MyCircularDeque {
public:
   map<int,int>mp;
   int sz;
   int f,b;
    MyCircularDeque(int k) {
        sz=k;
        f=sz+1;
        b=sz;
    }
    
    bool insertFront(int value) {
        if(mp.size()<sz){
            mp[b]=value;
             b--;
             return true;
        }else{
            return false;
        }
        
    }
    
    bool insertLast(int value) {
        if(mp.size()<sz){
           
           mp[f]=value;
            f++;
             return true;
        }else{
            return false;
        }
        
    }
    
    bool deleteFront() {
        if(mp.size()!=0){
            int val=(mp.begin())->first;
             mp.erase(val);
             b++;
             return true;

        }else{
            return false;
        }
    }
    
    bool deleteLast() {
        if(mp.size()!=0){
            int val=(mp.rbegin())->first;
        mp.erase(val);
        f--;
        return true;
        }else{
            return false;
        }
        
    }
    
    int getFront() {
        if(mp.size()==0){
            return -1;
        }
        int val=(mp.begin())->second;
        return val;
    }
    
    int getRear() {
        if(mp.size()==0){
            return -1;
        }
        int val=(mp.rbegin())->second;
        return val;
    }
    
    bool isEmpty() {
        return mp.size()==0;
    }
    
    bool isFull() {
        return mp.size()==sz;
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