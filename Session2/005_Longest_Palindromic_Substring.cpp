class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res = "";
        if(n == 0)
            return res;
        bool dp[n][n] = {0};
        // vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; i ++) {
            for(int j = i; j >= 0; j --)
                dp[i][j] = true;
        }
        int maxLen = 1;
        res = s[0];
        for(int l = 1; l < n; l ++) {
            for(int i = 0; i < n - l; i ++) {
                int j = i + l;
                if(s[i] == s[j] && dp[i + 1][j - 1]) {
                    maxLen = l + 1;
                    dp[i][j] = true;
                    res = s.substr(i, maxLen);
                }
            }
        }
        return res;
    }
};
