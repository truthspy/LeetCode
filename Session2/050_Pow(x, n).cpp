class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0)
            return 0;
        if(n == 0)
            return 1;
        if(x == 1.0)
            return x;
        if(n < 0) {
            x = 1.0 / x;
            if(n == INT_MIN) {
                n ++;
                n = -n;
                double res = posPow(x, n);
                return res * x;
            }
            n = -n;
        }
        return posPow(x, n);
    }
    double posPow(double x, int n) {
        if(n == 1)
            return x;
        int next = n / 2;
        double val = posPow(x, next);
        if(n % 2 == 0)
            return val * val;
        else
            return val * val * x;
    }
};
