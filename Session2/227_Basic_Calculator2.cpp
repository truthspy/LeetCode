// 因为没有括号，所以遇到*或者/可以直接计算结果
// 
class Solution {
public:
    int calculate(string s) {
        char sign = '+';
        stack<int> nums;
        int i = 0;
        while(i < s.length()) {
            if(s[i] >= '0' && s[i] <= '9') {
                int num = s[i] - '0';
                while(i + 1 < s.length() && s[i + 1] >= '0' && s[i + 1] <= '9') {
                    i ++;
                    num = num * 10 + (s[i] - '0');
                }
                if(sign == '+')
                    nums.push(num);
                else if(sign == '-')
                    nums.push(-num);
                else if(sign == '*') {
                    int val1 = nums.top();
                    nums.pop();
                    nums.push(val1 * num);
                }
                else {
                    int val1 = nums.top();
                    nums.pop();
                    nums.push(val1 / num);
                }
            }
            else if(s[i] != ' ')
                sign = s[i];
            i ++;
        }
        int res = 0;
        while(!nums.empty()) {
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};
