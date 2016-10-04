// @TODO 
// 1. 递归
// 2. 更简单的写法
class Solution {
public:
    string decodeString(string s) {
        stack<string> sStack;
        stack<int> reStack;
        string cur = "";
        for(int i = 0; i < s.length(); i ++) {
            if(s[i] == ']') {
                while(sStack.top() != "[") {
                    cur = sStack.top() + cur;
                    sStack.pop();
                }
                sStack.pop();
                int count = reStack.top();
                reStack.pop();
                string res = cur;
                while(count > 1) {
                    count --;
                    res += cur;
                }
                sStack.push(res);
                cur = "";
            }
            else if(s[i] >= '1' && s[i] <= '9') {
                sStack.push(cur);
                int pos = s.find('[', i + 1);
                cur = s.substr(i, pos - i);
                i = pos - 1;
            }
            else if(s[i] == '[') {
                reStack.push(atoi(cur.c_str()));
                sStack.push("[");
                cur = "";
            }
            else {
                cur += s[i];
            }
        }
        while(!sStack.empty()) {
            cur = sStack.top() + cur;
            sStack.pop();
        }
        return cur;
    }
};
