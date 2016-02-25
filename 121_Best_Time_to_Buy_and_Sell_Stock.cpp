class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int day = prices.size();
        if(day == 0)
            return 0;
        int profit = 0;
        int minPrice = prices[0];
        for(int i = 1; i < day; i ++) {
            if(prices[i] - minPrice > profit)
                profit = prices[i] - minPrice;
            if(prices[i] < minPrice)
                minPrice = prices[i];
        }
        return profit;
    }
};
