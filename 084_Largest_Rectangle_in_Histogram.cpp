/**
 * 比丢名言：栈里面存的是左边离它最近的比它小的
 * 还是看了答案
 * 大概hard就是想不出来吧。。。
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> dummy = heights;
        dummy.push_back(0);
        int len = dummy.size();
        stack<int> s;
        int maxArea = 0;
        cout << len;
        for(int i = 0; i < len; i ++) {
            while(!s.empty() && dummy[s.top()] > dummy[i]) {
                int t = s.top();
                s.pop();
                int w = 0;
                if(s.empty())
                    w = i;
                else
                    w = i - s.top() - 1;            //注意，要用s.top，不能用t，因为前面可能还有
                maxArea = max(maxArea, w * dummy[t]);
            }
            s.push(i);
        }
        return maxArea;
    }
};
