class MyQueue {
    Stack<Integer> st1 = new Stack<>();
    Stack<Integer> st2 = new Stack<>();
    
    public MyQueue() {
        
        
    }
    
    public void push(int x) {
        if(!st1.empty()){
            while(!st1.empty()){
                st2.push(st1.pop());
            }
            st2.push(x);
        } else{
            st2.push(x);            
        }
        
        while(!st2.empty()){
            st1.push(st2.pop());
        }       
        
    }
    
    public int pop() {
        if(!st1.empty()){
            return st1.pop();
        }
        return -1;
    }
    
    public int peek() {
        if(!st1.empty()){
            return st1.peek();
        }
        return -1;
    }
    
    public boolean empty() {
        return st1.empty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */