class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        int res = 0;
        stack<int> preHeight;
        for(int i = 0; i <= size; i ++) {
            int cur = -1;
            if(i < size)
                cur = i;        // 存的是下表，不是元素!!!
            while(!preHeight.empty() && heights[preHeight.top()] >= heights[cur]) {
                int h = heights[preHeight.top()];
                preHeight.pop();
                int r = i;      // 当前i位置的元素为右边第一个比它小的
                int l = -1;     // 如果左边没有比它小的，则左边界设为-1
                if(!preHeight.empty())
                    l = preHeight.top();
                int w = r - l - 1;
                res = max(res, h * w);
            }
            preHeight.push(cur);
        }
        return res;
    }
};
