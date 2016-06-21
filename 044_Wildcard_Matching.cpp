/**
 * Method1：dp勉强刚刚能过
 * Method2: TODO O(n)的贪心算法
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.length();
        int len2 = p.length();
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= len2; i ++) {
            if(p[i - 1] == '*')
                dp[0][i] = true;
            else
                break;
        }
        for(int i = 1; i <= len1; i ++) {
            for(int j = 1; j <= len2; j ++) {
                if(p[j - 1] == '*')
                    dp[i][j] = (dp[i - 1][j - 1] || dp[i][j - 1] || dp[i - 1][j]);
                else
                    dp[i][j] = (dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?'));
            }
        }
        return dp[len1][len2];
    }
};
