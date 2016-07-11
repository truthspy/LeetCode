class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> vals;
        int size = tokens.size();
        int val1 = 0;
        int val2 = 0;
        int res = 0;
        for(int i = 0; i < size; i ++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                val2 = vals.top();
                vals.pop();
                val1 = vals.top();
                vals.pop();
                if(tokens[i] == "+")
                    res = val1 + val2;
                else if(tokens[i] == "-")
                    res = val1 - val2;
                else if(tokens[i] == "*")
                    res = val1 * val2;
                else
                    res = val1 / val2;
                vals.push(res);
            }
            else
                vals.push(stoi(tokens[i]));
        }
        return vals.top();
    }
};
