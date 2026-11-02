class MinStack {
    vector<pair<int,int>> stack;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        int currentMin=stack.empty() ? value : min(value, stack.back().second);
        stack.push_back({value, currentMin});
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back().first;
    }
    
    int getMin() {
        return stack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */