class Solution {
public:
    bool isValid(string s) {
        stack<char> pStack;
        int len = s.length();
        for(int i = 0; i < len; i ++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                pStack.push(s[i]);
            else {
                if(pStack.empty())
                    return false;
                if(s[i] == ')')
                    if(pStack.top() != '(')
                        return false;
                else if(s[i] == ']')
                    if(pStack.top() != '[')
                        return false;
                else if(s[i] == '}')
                    if(pStack.top() != '{')
                        return false;
                pStack.pop();
            }
        }
        // 还要判断最后栈是否为空！！！！会出现"["这种情况
        if(!pStack.empty())
            return false;
        return true;
    }
};
