class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0)
            return 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int leftMin = prices[0];
        int rightMax = prices[n - 1];
        for(int i = 1; i < n; i ++) {
            leftMin = min(leftMin, prices[i]);
            left[i] = max(left[i - 1], prices[i] - leftMin);
        }
        for(int i = n - 2; i >= 0; i --) {
            rightMax = max(rightMax, prices[i]);
            right[i] = max(right[i + 1], rightMax - prices[i]);
        }
        int res = 0;
        for(int i = 0; i < n; i ++)
            res = max(res, left[i] + right[i]);
        return res;
    }
};
