/**
 * 背包问题
 * 第一反应是用dfs做，不合适
 * 花花给我讲的
 * 用DP做,dp[i]表示amount为i的最少组成数量。
 * dp[i] = min(dp[i], dp[i - coin[j]] + 1)
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        int size = coins.size();
        for(int i = 1; i <= amount; i ++) {
            for(int j = 0; j < size; j ++) {
                if(i - coins[j] < 0)
                    continue;
                if(dp[i - coins[j]] != INT_MAX)     //这里不能忘！！
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        if(dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};
