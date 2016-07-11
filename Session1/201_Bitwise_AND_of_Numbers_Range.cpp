/**
 * https://leetcode.com/discuss/32115/bit-operation-solution-java
 * last bit of (odd number & even number) is 0.
 * when m != n, There is at least an odd number and an even number, so the last bit position result is 0.
 * Move m and n rigth a position.
 */
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == 0)
            return 0;
        int i = 1;
        while(m != n) {
            m = m >> 1;
            n = n >> 1;
            i = i << 1;
        }
        return m * i;
    }
};
