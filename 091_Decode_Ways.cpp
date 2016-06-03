/**
 * 第一反应用dfs做
 * 看了tag之后告诉我用DP
 */
class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(len == 0)
            return len;
        vector<int> dp(len, 0);
        if(s[0] != '0') //防止出现“0”这种情况
            dp[0] ++;
        if(len == 1)
            return dp[0];
        if(stoi(s.substr(0, 2)) <= 26 && stoi(s.substr(0,2)) > 9) //要大于9，防止出现“01”这种情况
            dp[1] ++;
        if(s[1] != '0')
            dp[1] += dp[0];
        for(int i = 2; i < len; i ++) {
            if(s[i] != '0')
                dp[i] += dp[i - 1];
            if(stoi(s.substr(i - 1, 2)) <= 26 && stoi(s.substr(i - 1, 2)) > 9)
                dp[i] += dp[i - 2];
        }
        return dp[len - 1];
    }
};
