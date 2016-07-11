/*
思路：
用两个栈，一个栈正常存储
另一个栈：如果当前值比目前的最小值小（小于等于！！！），压栈，也即栈顶为最小值；
因为按照后进先出顺序，如果比目前的最小值大，那么当前的最小值一定会在它之后出栈，不会影响结果
*/
class MinStack {
public:
    stack<int> mystack;
    stack<int> minStack;
    
    void push(int x) {
        mystack.push(x);
        //注意判断栈为空的情况！
        if(minStack.empty())
            minStack.push(x);
        else {
            //！！！！防止重复元素出现，所以要加等于号！！！！！
            if(x <= minStack.top())
                minStack.push(x);
        }
    }

    void pop() {
        if(minStack.top() == mystack.top())
            minStack.pop();
        mystack.pop();
    }

    int top() {
        return mystack.top();
    }

    int getMin() {
        return minStack.top();
    }
};
