/*
思路 from discuss：
每次push操作都要保证这次压入的元素可以位于队列的front
*/
class Stack {
public:
    queue<int> Q;
    // Push element x onto stack.
    void push(int x) {
        int size = Q.size();
        Q.push(x);
        for(int i = 0; i < size; i ++) {
            Q.push(Q.front());
            Q.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        Q.pop();
    }

    // Get the top element.
    int top() {
        return Q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return Q.empty();
    }
};
