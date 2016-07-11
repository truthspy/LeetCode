/**
 * http://www.cnblogs.com/grandyang/p/5006441.html
 * 动归方程太难想了
 * 戳破i-j个气球最大能获得的金币数
 * dp[i][j] = max(nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]); i <= k <= j
 * 遍历的时候最外层循环要按长度遍历
 */
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for(int i = 0; i < n; i ++) {
            for(int l = 1; l <= n - i; l ++) {
                int r = l + i;
                for(int k = l; k <= r; k ++) {
                    int cur = nums[l - 1] * nums[r + 1] * nums[k];
                    cur += (dp[l][k - 1] + dp[k + 1][r]);
                    dp[l][r] = max(dp[l][r], cur);
                }
            }
        }
        return dp[1][n];
    }
};
