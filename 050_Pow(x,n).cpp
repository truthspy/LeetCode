//https://leetcode.com/discuss/52800/5-different-choices-when-talk-with-interviewers
/**solution 1
 * 每次把n向右移1位，同时x=x*x
 * 如果最右位为1，那么结果乘x
 * 否则，继续
 * 注意要判断n<0的情况
 */
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 && x != 0)
            return 1;
        double result = 1;
        if(n < 0) {
            x = 1.0 / x;
            if(n == INT_MIN) {
                n += 1;
                result *= x;
            }
            n = -n;
        }
        while(n > 0) {
            if(n & 1 == 1)
                result *= x;
            x = x * x;
            n = n >> 1;
        }
        return result;
    }
};

//https://leetcode.com/discuss/52800/5-different-choices-when-talk-with-interviewers
/**solution 2
 * 分治法
 * 如果n是2的倍数，那么result = pow(x*x, n / 2)
 * 否则，result = pow(x*x, n / 2) * x
 * 例子：3^15 = 3 * ((3^2)^7);
 */
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 1)
            return x;
        if(n == 0)
            return 1;
        double result = 1;
        if(n < 0) {
            x = 1.0 / x;
            if(n == INT_MIN) {
                n ++;
                result *= x;
            }
            n = -n;
        }
        result = result * myPow(x * x, n / 2);
        if(n % 2 != 0)
            result *= x;
        return result;
    }
};
