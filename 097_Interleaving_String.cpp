/**
 * DFS超时
 */
/*
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != (s1.length() + s2.length()))
            return false;
        return helper(s1, s2, s3, 0, 0, 0);
    }
    bool helper(string s1, string s2, string s3, int i, int j, int k) {
        if(k == (s3.length() + 1))
            return true;
        if(i < s1.length() && s1[i] == s3[k]) {
            if(helper(s1, s2, s3, i + 1, j, k + 1))
                return true;
        }
        if(j < s2.length() && s2[j] == s3[k]) {
            if(helper(s1, s2, s3, i, j + 1, k + 1))
                return true;
        }
        return false;
    }
};
*/
/**
 * 看Tag，要用DP
 * dp[i][j]表示s1的前i个元素与s2的前j个元素能否形成s3的前i+j个元素
 */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        if((len1 + len2) != s3.length())
            return false;
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= len1; i ++) {
            if(s1[i - 1] == s3[i - 1])
                dp[i][0] = true;
            else
                break;
        }
        for(int i = 1; i <= len2; i ++) {
            if(s2[i - 1] == s3[i - 1])
                dp[0][i] = true;
            else
                break;
        }
        for(int i = 1; i <= len1; i ++) {
            for(int j = 1; j <= len2; j ++) {
                if(dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
                    dp[i][j] = true;
                else if(dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = true;
            }
        }
        return dp[len1][len2];
    }
};
