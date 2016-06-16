class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        vector<int> candies(len, 1);
        int total = len;
        for(int i = 1; i < len; i ++) {
            if(ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
                int diff = candies[i - 1] + 1 - candies[i];
                candies[i] = candies[i - 1] + 1;
                total += diff;
            }
        }
        for(int i = len - 2; i >= 0; i --) {
            if(ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                int diff = candies[i + 1] + 1 - candies[i];
                candies[i] = candies[i + 1] + 1;
                total += diff;
            }
        }
        return total;
    }
};
