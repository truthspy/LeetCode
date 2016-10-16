class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.length();
        int len2 = p.length();
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= len2; i ++) {
            if(p[i - 1] == '*') {
                if(i > 1)
                    dp[0][i] = dp[0][i - 2];
                if(dp[0][i] == false)
                    break;
            }
        }
        for(int i = 1; i <= len1; i ++) {
            for(int j = 1; j <= len2; j ++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if(j > 1 && p[j - 1] =='*') {
                    dp[i][j] = dp[i][j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]); //最后一项是dp[i - 1][j]不是dp[i-1][j-2]
                }
                else
                    dp[i][j] =false;
            }
        }
        return dp[len1][len2];
    }
};
