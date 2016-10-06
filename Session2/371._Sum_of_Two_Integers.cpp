// 看答案
// a + b = (a ^ b) + (a & b) << 1
// a ^ b是a+b不考虑进位的结果
// a&b是进位，进位向前移以为和a^b相加，即为结果
class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0) {
            int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }
};
