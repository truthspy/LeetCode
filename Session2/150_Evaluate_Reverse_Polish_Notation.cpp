class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(int i = 0; i < tokens.size(); i ++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int val2 = nums.top();
                nums.pop();
                int val1 = nums.top();
                nums.pop();
                int res = 0;
                if(tokens[i] == "+")
                    res = val1 + val2;
                else if(tokens[i] == "-")
                    res = val1 - val2;
                else if(tokens[i] == "*")
                    res = val1 * val2;
                else
                    res = val1 / val2;
                nums.push(res);
            }
            else
                nums.push(atoi(tokens[i].c_str()));
        }
        return nums.top();
    }
};
