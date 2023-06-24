class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        int y;
        if(s1.empty()){
            s1.push(x);
            return;
        }
        while(!s1.empty()){
            y = s1.top();
            s2.push(y);
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            y = s2.top();
            s2.pop();
            s1.push(y);
        }
    }
    
    int pop() {
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        if(s1.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */