/**
 * 动归方程比较绕，还得再看看TODO
 * 设状态为 f(i,j),表示T[0,j]在S[0,i]里出现的次数。首先,无论T[j]和S[i]是否相等,若不使用S[i],则 f(i,j) = f(i − 1,j);
 * 若T[j] = S[i],则可以使用S[i],此时 f(i, j) = f(i − 1, j) + f(i − 1, j − 1)。
 */
class Solution {
public:
    int numDistinct(string s, string t) {
        int sSize = s.length();
        int tSize = t.length();
        vector<vector<int>> dp(sSize + 1, vector<int>(tSize + 1, 0));
        for(int i = 0; i <= sSize; i ++)
            dp[i][0] = 1;
        for(int i = 1; i <= sSize; i ++) {
            for(int j = 1; j <= tSize; j ++) {
                if(s[i - 1] != t[j - 1])     //i&j表示的都是从1开始计数的第i位，所以要记着-1
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
        return dp[sSize][tSize];
    }
};
