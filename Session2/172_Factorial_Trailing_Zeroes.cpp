class Solution {
public:
    int trailingZeroes(int n) {
        long long val = 5;
        int count = 0;
        while(val <= n) {
            count += (n / val);
            val = val * 5;
        }
        return count;
    }
};
