class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        int res = 10;
        for(int i = 2; i <= n; i ++) {
            if(i > 10)
                break;
            int cur = 9;
            int num = 9;
            for(int j = i - 1; j >= 1; j --) {
                cur *= num;
                num --;
            }
            res += cur;
        }
        return res;
    }
};
