class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> ball(n + 2, 1);
        for(int i = 0; i < n; i ++)
            ball[i + 1] = nums[i];
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for(int i = 1; i <= n; i ++)
            dp[i][i] = ball[i - 1] * ball[i] * ball[i + 1];
        for(int len = 1; len < n; len ++) {
            for(int i = 1; i + len <= n; i ++) {
                int j = i + len;
                for(int k = i; k <= j; k ++) {
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + ball[i - 1] * ball[k] * ball[j + 1]);
                }
            }
        }
        return dp[1][n];
    }
};
