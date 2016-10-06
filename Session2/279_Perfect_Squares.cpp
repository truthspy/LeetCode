class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for(int i = 2; i <= n; i ++) {
            int factor = sqrt(i);
            if(factor * factor == i) {
                dp[i] = 1;
                continue;
            }
            dp[i] = i;
            // 太慢了！
            /*
            for(int j = i - 1; j >= (i / 2); j --) {
                dp[i] = min(dp[i], dp[j] + dp[i - j]);
            }*/
            // i肯定是由某个完全平方数l=j*j，与(i - j*j)的和组成
            // 只需要遍历1到j即可
            for(int j = 1; j <= factor; j ++) 
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
        return dp[n];
    }
};
