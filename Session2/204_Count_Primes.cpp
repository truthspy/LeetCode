class Solution {
public:
    int addDigits(int num) {
        while(num >= 10) {
            int cur = num;
            num = 0;
            while(cur != 0) {
                num += cur % 10;
                cur = cur / 10;
            }
        }
        return num;
    }
};
