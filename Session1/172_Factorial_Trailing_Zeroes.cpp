/*
http://www.cnblogs.com/ganganloveu/p/4193373.html
对n!做质因数分解n!=2x*3y*5z*...
显然0的个数等于min(x,z)，并且min(x,z)==z
*/
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        long i = 5;
        while(i <= n) {
            count += (n / i);
            i = i * 5;
        }
        return count;
    }
};
