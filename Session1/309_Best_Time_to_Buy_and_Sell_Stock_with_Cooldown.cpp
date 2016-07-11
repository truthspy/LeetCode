/**
 * 有限状态机
 * https://leetcode.com/discuss/72030/share-my-dp-solution-by-state-machine-thinking
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size <= 1)
            return 0;
        vector<int> s0(size, 0);
        vector<int> s1(size, 0);
        vector<int> s2(size, 0);
        s1[0] = -prices[0];
        s2[0] = INT_MIN;
        for(int i = 1; i < size; i ++) {
            s0[i] = max(s0[i - 1], s2[i - 1]);
            s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
            s2[i] = s1[i - 1] + prices[i];
        }
        return max(s0[size - 1], s2[size - 1]);
    }
};
