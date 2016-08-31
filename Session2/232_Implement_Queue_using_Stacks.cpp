class Queue {
private:
    stack<int> inStack;
    stack<int> outStack;
public:
    // Push element x to the back of queue.
    void push(int x) {
        inStack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(outStack.empty()) {
            while(!inStack.empty()) {
                int cur = inStack.top();
                inStack.pop();
                outStack.push(cur);
            }
        }
        outStack.pop();
    }

    // Get the front element.
    int peek(void) {
        if(outStack.empty()) {
            while(!inStack.empty()) {
                int cur = inStack.top();
                inStack.pop();
                outStack.push(cur);
            }
        }
        return outStack.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (inStack.empty() && outStack.empty());
    }
};
