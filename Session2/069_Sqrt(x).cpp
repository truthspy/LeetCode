
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1)
            return x;
        int l = 1;
        int r = x / 2;
        // !! "<="
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int tmp = x / mid;
            if(tmp == mid)
                return mid;
            if(tmp > mid)
                l = mid + 1;
            else
                r = mid - 1;
        }
        // return r not l!!
        return r;
    }
};
