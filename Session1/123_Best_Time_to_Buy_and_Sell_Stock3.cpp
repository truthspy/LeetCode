/**
 * 看了花花的简书，写得好啊
 * http://www.jianshu.com/p/8723c211a4b6
 * 因为不能同时持有两支股票，
 * 所以pre[i]记录第i天前卖第一支股票赚的最大值，post[i]记录第i天后买第2支股票赚的最大值
 * result = max(pre[i]+pos[i])
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<int> pre(size, 0);
        vector<int> post(size, 0);
        int low = INT_MAX;
        int preMax = 0;
        for(int i = 0; i < size; i ++) {
            low = min(low, prices[i]);
            preMax = max(preMax, prices[i] - low);
            pre[i] = preMax;            //pre[i]是i天之前的最大值，而不是在第i天卖的最大值，post[i]同理
        }
        int high = INT_MIN;
        int postMax = 0;
        for(int i = size - 1; i >= 0; i --) {
            high = max(high, prices[i]);
            postMax = max(postMax, high - prices[i]);
            post[i] = postMax;
        }
        int res = 0;
        for(int i = 0; i < size; i ++)
            res = max(res, pre[i] + post[i]);
        return res;
    }
};
