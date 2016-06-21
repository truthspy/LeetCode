/**
 * 显然不看答案是不会做的
 * Method1(没写): 将每一层向上看成是直方图，那么就转换成Largest Rectangle in Histogram这道题了TODO
 * Method2: 
 * 矩形为(right[j] - left[j]) * height[j]
 * height counts the number of successive '1's above (plus the current one). 
 * The value of left & right means the boundaries of the rectangle 
 * which contains the current point with a height of value height
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        vector<int> height(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, n);
        int maxArea = 0;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j] ++;
            }
            int curLeft = 0;
            for(int j = 0; j < n; j ++) {
                if(matrix[i][j] == '1')
                    left[j] = max(left[j], curLeft);    //max函数中的left[j]存的是i-1,j位置的left值
                else {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }
            int curRight = n;
            for(int j = n - 1; j >= 0; j --) {
                if(matrix[i][j] == '1')
                    right[j] = min(right[j], curRight);
                else {
                    right[j] = n;   //如果为0，要置为最右边
                    curRight = j;
                }
            }
            for(int j = 0; j < n; j ++)
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
        }
        return maxArea;
    }
};
