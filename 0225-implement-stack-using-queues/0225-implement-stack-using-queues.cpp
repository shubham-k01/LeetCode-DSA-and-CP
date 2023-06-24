class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.empty()){
            q1.push(x);
            return;
        }
        int m,y = q1.size();
        q1.push(x);
        for(int i=0;i<y;i++){
            m = q1.front();
            q1.pop();
            q1.push(m);
        }
        return;
    }
    
    int pop() {
        if(q1.empty()){
            return -1;
        }
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        if(q1.empty()){
            return -1;
        }
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */