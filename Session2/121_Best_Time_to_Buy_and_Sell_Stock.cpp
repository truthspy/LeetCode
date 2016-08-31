class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int curMin = INT_MAX;
        for(int i = 0; i < prices.size(); i ++) {
            res = max(res, prices[i] - curMin);
            curMin = min(curMin, prices[i]);
        }
        return res;
    }
};
