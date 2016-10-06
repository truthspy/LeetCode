class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1)
            return 1;
        vector<int> res;
        res.push_back(1);
        int i = 0, j = 0, k = 0;
        int count = 1;
        while(count < n) {
            count ++;
            int cur = min(res[i] * 2, min(res[j] * 3, res[k] * 5));
            res.push_back(cur);
            if(cur == res[i] * 2)
                i ++;
            if(cur == res[j] * 3)
                j ++;
            if(cur == res[k] * 5)
                k ++;
        }
        return res[n - 1];
    }
};
