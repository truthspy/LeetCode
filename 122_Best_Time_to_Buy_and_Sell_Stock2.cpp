//slow version
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int max = 0;
        int size = prices.size();
        int profit = 0;
        bool findMin = true;
        for(int i = 0; i < size; i ++) {
            if(findMin && prices[i] <= min)
                min = prices[i];
            else if(findMin) {
                findMin = false;
                max = prices[i];
            }
            else if(prices[i] >= max)
                max = prices[i];
            else {
                profit += (max - min);
                min = prices[i];
                findMin = true;
            }
        }
        //最后末尾要记着单独处理！！！
        if(!findMin)
            profit += (max - min);
        return profit;
    }
};

//new version, faster
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int profit = 0;
        for(int i = 0; i < size; i ++) {
            if(i != 0 && prices[i] > prices[i - 1])
                profit += (prices[i] - prices[i - 1]);
        }
        return profit;
    }
};
