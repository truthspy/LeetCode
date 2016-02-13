class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0 || n == 2)
            return false;
        while(n != 1 && n != 2) {
            if(n % 3 != 0)
                return false;
            n = n / 3;
        }
        if(n == 1)
            return true;
        return false;
    }
};
