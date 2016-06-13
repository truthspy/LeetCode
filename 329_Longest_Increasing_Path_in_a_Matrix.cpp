/**
 * 看了答案
 */
class Solution {
public:
    int direction[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        if(n == 0)
            return 0;
        int maxLen = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                int cur = dfs(matrix, m, n, dp, i, j);
                maxLen = max(maxLen, cur);
            }
        }
        return maxLen;
    }
    int dfs(vector<vector<int>>& matrix, int m, int n, vector<vector<int>>& dp, int i, int j) {
        if(dp[i][j] != 0)
            return dp[i][j];
        dp[i][j] = 1;
        for(int k = 0; k < 4; k ++) {
            int x = i + direction[k][0];
            int y = j + direction[k][1];
            if(x < 0 || y < 0 || x >= m || y >= n || matrix[x][y] <= matrix[i][j])
                continue;
            dp[i][j] = max(dp[i][j], 1 + dfs(matrix, m, n, dp, x, y));
        }
        return dp[i][j];
    }
};
