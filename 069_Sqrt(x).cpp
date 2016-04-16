class Solution {
public:
    int mySqrt(int x) {
        return search(x, 0, x);
    }
    int search(int x, int l, int r) {
        if(r < l)
            return r;
        long mid = l + (r - l) / 2;
        if(mid * mid == x)
            return mid;
        if(mid * mid < x)
            return search(x, mid + 1, r);
        else
            return search(x, l, mid - 1);
    }
};
