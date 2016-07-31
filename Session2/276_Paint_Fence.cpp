// 丢给我讲的
class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0 || k == 0)
            return 0;
        int same = 0;
        int diff = k;
        for(int i = 2; i <= n; i ++) {
            int lastDiff = diff;
            diff = (same + diff) * (k - 1);
            same = lastDiff;
        }
        return (diff + same);
    }
};
