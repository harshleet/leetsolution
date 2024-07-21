class MinStack {
public:
stack<pair<int, long long int>>st;
   long long int mini;

    MinStack() {
        mini=LLONG_MAX;    
    }
    void push(int val) {
         long long int vl=val;
       mini=min(mini,vl);

       st.push({val,mini});   
    }
    
    void pop() {
        st.pop();
        if (!st.empty()) {
            mini = st.top().second;
        } else {
            mini = LLONG_MAX;
        }
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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