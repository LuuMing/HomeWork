class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> data;
    vector<int> minData;
    MinStack() {
        minData.push_back(INT_MAX);
    }
    
    void push(int x) {
        data.push_back(x);
        minData.push_back(min(minData.back(),x));
    }
    
    void pop() {
        data.pop_back();
        minData.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return minData.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
