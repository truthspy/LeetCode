/**
 * 看了discuss
 * https://leetcode.com/discuss/38489/easy-solution-with-detailed-explanations-8ms-time-and-space
 * dp[i][j]记录以i,j作为右下角，可以形成的最大的正方形的边长
 * dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0)
            return 0;
        int col = matrix[0].size();
        int maxSize = 0;
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for(int i = 0; i < row; i ++) {
            dp[i][0] = matrix[i][0] - '0';
            maxSize = max(maxSize, dp[i][0]);
        }
        for(int j = 0; j < col; j ++) {
            dp[0][j] = matrix[0][j] - '0';
            maxSize = max(maxSize, dp[0][j]);
        }
        for(int i = 1; i < row; i ++)
            for(int j = 1; j < col; j ++) {
                if(matrix[i][j] == '0')
                    dp[i][j] = 0;
                else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]) + 1;
                    maxSize= max(maxSize, dp[i][j]);
                }
            }
        return maxSize * maxSize;
    }
};
