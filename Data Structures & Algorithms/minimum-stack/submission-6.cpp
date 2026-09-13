class MinStack {
public:
stack<int>s;
stack<int>minstack;
    MinStack() {
    }
    

    void push(int val) {
    if(minstack.empty() || val<=minstack.top()){
        minstack.push(val);
    } 
    s.push(val);   
    }
    
    void pop() {
        if(minstack.top()==s.top()){
            minstack.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
