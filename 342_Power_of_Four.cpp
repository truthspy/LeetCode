/**
 * TODO
 * 无recursion/loop的方法要再看discuss
 */
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0)
            return false;
        while(num != 1) {
            if(num % 4 != 0)
                return false;
            num = num / 4;
        }
        return (num == 1);
    }
};
