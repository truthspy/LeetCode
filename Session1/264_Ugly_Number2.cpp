class Solution {
public:
    int nthUglyNumber(int n) {
        int i = 0, j = 0, k = 0;
        vector<int> val(n, 1);
        int m = 1;
        while(m < n) {
            val[m] = min(min(2 * val[i], 3 * val[j]), 5 * val[k]);
            //注意：有可能某个数既是2的倍数也是3的倍数，比如6
            //所以不能用else if判断
            //6的时候2和3的指针都要往后移
            //指针往后移不是某个数++，而是位置++!!!!!!!!!!也就是说，是unglyNumber中的数乘2、3、5比较
            if(val[m] == 2 * val[i])
                i ++;
            if(val[m] == 3 * val[j])
                j ++;
            if(val[m] == 5 * val[k])
                k ++;
            m ++;
        }
        return val[n - 1];
    }
};
