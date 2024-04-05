class MinStack {
    
    Stack<Integer> st1;
    Stack<Integer> st2;

    public MinStack() {
        st1 = new Stack<>();
        st2 = new Stack<>();
    }
    
    public void push(int val) {
        st1.push(val);
        if(st2.empty() || val <= st2.peek()) st2.push(val);
    }
    
    public void pop() {
        if(st1.peek().equals(st2.peek())) st2.pop();
        st1.pop();  
    }
    
    public int top() {
        if(!st1.isEmpty()) return st1.peek();
        return -1; 
    }
    
    public int getMin() {
        if(!st2.isEmpty()) return st2.peek();
        return -1; 
    }
}
