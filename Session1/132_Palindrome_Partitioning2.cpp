/**
 * 果然我的方法会超时，还是看答案吧
 * 优化1：用一个数组记录[i,j]是否是回文，不用每次判断，可以动归求这个数组p
 * 优化2：记录前k个字符的划分情况即可，不用记录i-j的情况：dp[i] = min(1+dp[j]) (如果p[j+1][i], 0<=j<i),或者=0(p[0][i))
 * TODO更简洁更快的代码
 */
class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        vector<int> dp(len, INT_MAX);
        vector<vector<bool>> p(len, vector<bool>(len, false)); 
        //用一个数组记录[i,j]是否是回文，不用每次判断，可以动归求这个数组
        
        for(int k = 0; k < len; k ++) {
            for(int i = 0; i < len - k; i ++) {
                int j = i + k;
                if(s[i] == s[j]) {
                    if((i + 1) > (j - 1))
                        p[i][j] = true;
                    else
                        p[i][j] = p[i + 1][j - 1];
                }
                else
                    p[i][j] = false;
            }
        }
        
        for(int i = 0; i < len; i ++) {         //i表示前i个字符
            if(p[0][i]) {
                dp[i] = 0;
                continue;
            }
            for(int j = 0; j < i; j ++) {
                if(p[j + 1][i])
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[len - 1];
    }
};

/*
超时的方法TT
class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, INT_MAX));
        vector<vector<bool>> p(len, vector<bool>(len, false)); 
        //用一个数组记录[i,j]是否是回文，不用每次判断，可以动归求这个数组
        
        for(int k = 0; k < len; k ++) {
            for(int i = 0; i < len - k; i ++) {
                int j = i + k;
                if(s[i] == s[j]) {
                    if((i + 1) > (j - 1))
                        p[i][j] = true;
                    else
                        p[i][j] = p[i + 1][j - 1];
                }
                else
                    p[i][j] = false;
            }
        }
        
        for(int k = 0; k < len; k ++) {         //k表示子串长度
            for(int j = 0; j < len - k; j ++) {     //j表示起始位置, j+k是终止位置
                int i = j + k;
                if(p[j][i])
                    dp[j][i] = 0;
                else {
                    for(int m = j; m < i; m ++) {
                        int cur = dp[j][m] + dp[m + 1][i] + 1;  //左+右+1
                        dp[j][i] = min(cur, dp[j][i]);
                    }
                }
            }
        }
        return dp[0][len - 1];
    }
};
*/
