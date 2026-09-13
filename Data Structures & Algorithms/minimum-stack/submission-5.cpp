class MinStack {
public:
    int topIndex;
    int a1[1000]; // fixed size
    MinStack() {
        topIndex = -1;
    }
    
    void push(int val) {
        topIndex++;
        a1[topIndex] = val;
    }
    
    void pop() {
        topIndex--;
    }
    
    int top() {
        return a1[topIndex];
    }
    
    int getMin() {
        int l1 = INT_MAX;
        for(int i=0; i <= topIndex; i++){
            l1 = min(l1, a1[i]);
        }
        return l1;
    }
};
