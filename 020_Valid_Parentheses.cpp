class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        int len = s.length();
        for(int i = 0; i < len; i ++) {
            if(s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[')
                mystack.push(s.at(i));
            else {
                /*
                易错！！
                需要考虑形如"]"的输入情况，top之前需保证stack不为空！
                */
                if(mystack.empty())
                    return false;
                char tmp = mystack.top();
                if(s.at(i) == ')') {
                    if(tmp == '(')
                        mystack.pop();
                    else
                        return false;
                }
                else if(s.at(i) == '}') {
                    if(tmp == '{')
                        mystack.pop();
                    else
                        return false;
                }
                else if(s.at(i) == ']') {
                    if(tmp == '[')
                        mystack.pop();
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        return mystack.empty();
    }
};
