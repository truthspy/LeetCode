/*
思路 from discuss：
每次push操作都要保证这次压入的元素可以位于队列的front
从第一个就开始这样操作，可以保证queue里的倒序
*/
class Stack {
private:
    queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        int size = q.size();
        q.push(x);
        for(int i = 0; i < size; i ++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};
