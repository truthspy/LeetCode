//思路：cracking p55
//不断将1左移一位，与n“按位与”，如果为1，说明该位为1

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t tmp = 0;
        uint32_t mask = 1;
        int i = 0;
        int count = 0;
        while(i < 32) {
            tmp = n & mask;
            if(tmp != 0)
                count ++;
            mask = mask << 1;
            i ++; //易忘！
        }
        return count;
    }
};
