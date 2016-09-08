class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if(x == 0)
            return 0;
        if(x < 0) {
            neg = true;
            x = 0 - x;
        }
        int res = 0;
        while(x != 0) {
            int pre = res;
            res = res * 10 + (x % 10);
            x = x / 10;
            // 防溢出，通过和乘10之前的数比较，来判断是否溢出
            if(res / 10 != pre)
                return 0;
        }
        if(neg)
            res = 0 - res;
        return res;
    }
};
