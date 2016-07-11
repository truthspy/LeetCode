class Solution {
public:
    int sumOfSquare(int n) {
        int result = 0;
        while(n != 0) {
            int tmp = n % 10;
            result += (tmp * tmp);
            n = n / 10;
        }
        return result;
    }
    bool isHappy(int n) {
        if(n <= 0)
            return false;
        if(n == 1)
            return true;
        int flag[1000] = {0};
        int result = sumOfSquare(n);
        while(result != 1 && flag[result] == false) {
            flag[result] = true;
            result = sumOfSquare(result);
        }
        if(result == 1)
            return true;
        return false;
    }

};
