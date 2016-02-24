/*
思路：
从最低位到最高位，每次取出n中的一位
从低到高的实现方法：每次把n向右移一位，与1进行与操作，得到的就是当前最后一位
然后将结果左移一位，并和n的当前最后一位进行或操作
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverse = 0;
        for(int i = 0; i < 32; i ++) {
            reverse = (reverse << 1) | (n & 1);
            n = n >> 1;
        }
        return reverse;
    }
};
