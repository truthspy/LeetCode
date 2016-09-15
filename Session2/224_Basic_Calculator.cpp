class Solution {
public:
    int calculate(string s) {
        int res = 0;
        stack<int> nums;
        stack<int> op;
        int sign = 1;
        int i = 0;
        while(i < s.length()) {
            if(s[i] >= '0' && s[i] <= '9') {
                int num = s[i] - '0';
                while(i + 1 < s.length() && ((s[i + 1] >= '0' && s[i + 1] <= '9') || s[i + 1] == ' ')) {
                    i ++;
                    if(s[i] == ' ')
                        continue;
                    num = num * 10 + (s[i] - '0');
                }
                res += (sign * num);
            }
            else if(s[i] == '+') {
                sign = 1;
            }
            else if(s[i] == '-') {
                sign = -1;
            }
            else if(s[i] == '(') {
                nums.push(res);
                op.push(sign);
                res = 0;
                sign = 1;
            }
            else if(s[i] == ')') {
                res = res * op.top() + nums.top();
                op.pop();
                nums.pop();
            }
            i ++;
        }
        return res;
    }
};
