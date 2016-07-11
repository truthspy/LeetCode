/**
 * 花花给我讲的
 * 花花说还有另一种方法，但是我没看明白
 * Huahua asked me to write comments in English T_T
 * local[i][j] = max(local[i-1][j] + diff, global[i-1][j-1]+max(diff,0))
 * global[i][j] = max(global[i-1][j], local[i][j])
 * TODO 再看再看再看（重要的事情说三次）呀不对，花花让我写英文
 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        int result = 0;
        if(k > (len / 2)) {
            for(int i = 1; i < len; i ++) {
                if(prices[i] > prices[i - 1])
                    result += (prices[i] - prices[i - 1]);
            }
            return result;
        }
        vector<vector<int>> local(len, vector<int>(k + 1, 0));
        vector<vector<int>> global(len, vector<int>(k + 1, 0)); //初始化和边界条件还得看
        for(int i = 1; i < len; i ++) {
            int diff = prices[i] - prices[i - 1];
            for(int j = 1; j <= k; j ++) {
                local[i][j] = max(local[i-1][j] + diff, global[i-1][j-1]+max(diff,0));
                global[i][j] = max(global[i-1][j], local[i][j]);
            }
        }
        return global[len-1][k];
    }
};
