// O(1) solution
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        return ((n & (n - 1)) == 0);
    }
};
/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        if(n == 1)
            return true;
        while(n > 1) {
            if(n % 2 == 1)
                return false;
            n = n / 2;
        }
        return true;
    }
};
*/
