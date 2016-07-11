/**
 * Method1：TODO
 * DP方法：http://bangbingsyb.blogspot.com/2014/11/leetcode-longest-valid-parentheses.html
 * Method2：
 * 看了答案
 * 
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        stack<int> parent;
        int maxLen = 0;
        int start = 0;
        for(int i = 0; i < s.length(); i ++) {
            if(s[i] == '(')
                parent.push(i);
            else {
                if(!parent.empty()) {
                    // int start = parent.top(); 这样不对，比如()()的情况，start是0不是1
                    parent.pop();
                    if(parent.empty())
                        maxLen = max(maxLen, i - start + 1);  //start记录的是断开后的起始位置
                    else
                        maxLen = max(maxLen, i - parent.top());         //左括号多的情况
                }
                else
                    start = i + 1;
            }
        }
        return maxLen;
    }
};
