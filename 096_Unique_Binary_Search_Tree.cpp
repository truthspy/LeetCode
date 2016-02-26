/*
看了答案
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp;
        dp.push_back(1);
        dp.push_back(1);
        int i = 2;
        while(i <= n) {
            int tmp = 0;
            for(int j = 1; j <= i; j ++) {
                tmp += dp[j - 1] * dp[i - j];
            }
            dp.push_back(tmp);
            i ++;
        }
        return dp[n];
    }
};
