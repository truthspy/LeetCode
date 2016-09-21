class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for(int i = 0; i < m; i ++) {
            if(matrix[i][0] == '1') {
                dp[i][0] = 1;
                res = max(dp[i][0], res);
            }
        }
        for(int i = 1; i < n; i ++) {
            if(matrix[0][i] == '1') {
                dp[0][i] = 1;
                res = max(dp[0][i], res);
            }
        }
        for(int i = 1; i < m; i ++) {
            for(int j = 1; j < n; j ++) {
                if(matrix[i][j] == '1') {
                    int cur = min(dp[i][j - 1], dp[i - 1][j]);
                    cur = min(cur, dp[i - 1][j - 1]);
                    dp[i][j] = cur + 1;
                    res = max(dp[i][j], res);
                }
            }
        }
        return res * res;
    }
};
