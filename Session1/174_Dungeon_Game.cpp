/**
 * 最开始一直想的是从左上角向右下角扩展动归，发现行不通
 * 看了答案才会做
 * 从右下角向左上角扩展动归
 * TODO
 * 想想怎么简化，还有点乱
 */
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if(m == 0)
            return 0;
        int n = dungeon[0].size();
        if(n == 0)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n));
        if(dungeon[m - 1][n - 1] > 0)
            dp[m - 1][n - 1] = 1;
        else
            dp[m - 1][n - 1] = 1 - dungeon[m - 1][n - 1];
        for(int j = n - 2; j >= 0; j --) {
            int i = m - 1;
            int curMin = dp[i][j + 1];
            if(curMin <= 0) {
                if(dungeon[i][j] >= 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1 - dungeon[i][j];
            }
            else
                dp[i][j] = curMin - dungeon[i][j];
        }
        for(int i = m - 2; i >= 0; i --) {
            int j = n - 1;
            int curMin = dp[i + 1][j];
            if(curMin <= 0) {
                if(dungeon[i][j] >= 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1 - dungeon[i][j];
            }
            else
                dp[i][j] = curMin - dungeon[i][j];
        }
        for(int i = m - 2; i >= 0; i --) {
            for(int j = n - 2; j >= 0; j --) {
                int curMin = min(dp[i + 1][j], dp[i][j + 1]);
                if(curMin <= 0) {
                    if(dungeon[i][j] >= 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 1 - dungeon[i][j];
                }
                else
                    dp[i][j] = curMin - dungeon[i][j];
            }
        }
        if(dp[0][0] <= 0)
            dp[0][0] = 1;
        return dp[0][0];
        
    }
};
