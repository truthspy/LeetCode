// 看了答案抄的。。
/*
Straight forward way to solve the problem in 3 steps:
1. find the length of the number where the nth digit is from
2. find the actual number where the nth digit is from
3. find the nth digit and return
*/
// TODO
// 要注意下标，判断的时候用n-1
class Solution {
public:
    int findNthDigit(int n) {
        int len = 1;
        long long count = 9;
        int start = 1;
        while(n > len * count) {
            n -= (len * count);
            len ++;
            count *= 10;
            start *= 10;
        }
        int num = start + ((n - 1) / len);
        string cur = to_string(num);
        int res = cur[(n - 1) % len] - '0';
        return res;
    }
};
