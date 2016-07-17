class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> nums;
    stack<int> minNums;
    MinStack() {
        
    }
    
    void push(int x) {
        nums.push(x);
        if(minNums.empty() || minNums.top() >= x)
            minNums.push(x);
    }
    
    void pop() {
        if(!nums.empty()) {
            int cur = nums.top();
            nums.pop();
            int curMin = minNums.top();
            if(cur == curMin)
                minNums.pop();
        }
    }
    
    int top() {
        if(!nums.empty())
            return nums.top();
        return -1;
    }
    
    int getMin() {
        if(!minNums.empty())
            return minNums.top();
        return -1;
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
