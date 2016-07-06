class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 0)
            return false;
        if(num <= 1)
            return true;
        int l = 0;
        int r = num;
        while(l <= r) {
            long long mid = l + (r - l) / 2;
            long long cur = mid * mid;
            if(cur == num)
                return true;
            if(cur > num)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};
