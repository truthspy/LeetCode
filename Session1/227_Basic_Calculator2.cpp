/**
 * TODO
 * 压入数字的时候带‘-’一起计入，这样就可以用栈实现
 * 还可以不用栈， one pass
 */
class Solution {
public:
    int calculate(string s) {
        vector<int> vals;
        vector<char> ops;
        int cur = 0;
        int len = s.length();
        char op = '+';
        for(int i = 0; i < len; i ++) {
            if(i != (len - 1) && s[i] == ' ')
                continue;
            if(s[i] >= '0' && s[i] <= '9')
                cur = cur * 10 + s[i] - '0';
            if(s[i] < '0' || s[i] > '9' || i == len - 1) {
                if(op == '+' || op == '-')
                    vals.push_back(cur);
                else if(op == '*') {
                    int res = vals[vals.size() - 1] * cur;
                    vals.pop_back();
                    vals.push_back(res);
                }
                else if(op == '/'){
                    int res = vals[vals.size() - 1] / cur;
                    vals.pop_back();
                    vals.push_back(res);
                }
                if(i != (len - 1)) {
                    cur = 0;
                    op = s[i];
                    if(op == '+' || op == '-')
                        ops.push_back(op);
                }
            }
            
        }
        for(int i = 0; i < ops.size(); i ++) {
            int res;
            if(ops[i] == '+')
                res = vals[0] + vals[1];
            else
                res = vals[0] - vals[1];
            vals[1] = res;
            vals.erase(vals.begin());
        }
        return vals[0];
    }
};
