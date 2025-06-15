class MinStack {
private:
    std::vector<int> stack;
    std::vector<int> minStack;  

public:
    MinStack() {
    }
    
    void push(int val) {
        stack.push_back(val);
        
        if(minStack.empty() || val <= minStack.back()) {
            minStack.push_back(val);
        }
    }
    
    void pop() {
        if (stack.empty()) return;
        
        int topVal = stack.back();
        stack.pop_back();
        
        if (topVal == minStack.back()) {
            minStack.pop_back();
        }
    }
    
    int top() {
        if (stack.empty()) return INT_MIN; 
        return stack.back();
    }
    
    int getMin() {
        if (minStack.empty()) return INT_MIN;
        return minStack.back();  
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