class MinStack {
public:
   stack<int>st;
   map<int,int>m;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        m[val]++;
    }
    
    void pop() {
        int val=st.top();
        st.pop();
        m[val]--;
        if(m[val]==0){
            m.erase(val);
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return m.begin()->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */