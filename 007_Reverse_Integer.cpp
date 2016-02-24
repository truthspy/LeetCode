class Solution {
public:
    int reverse(int x) {
        bool neg = 0;
        if(x < 0) {
            neg = 1;
            x = 0 - x;
        }
        int rev = 0;
        while(x > 0) {
            int last = rev;
            rev = rev * 10 + x % 10;
            x = x / 10;
            /*
            为防止溢出，记录上一步的计算结果，
            如果当前结果除10与上一步结果不同，说明溢出
            */
            if(rev / 10 != last) {
                rev = 0;
                break;
            }
        }
        if(neg)
            rev = 0 - rev;
        return rev;
    }
};
