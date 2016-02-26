//这个不好，还有动归的方法，待看
class Solution {
public:
    int uniquePaths(int m, int n) {
        int total = (m - 1) + (n - 1);
        int k = min(m - 1,n - 1);
        long long count1 = 1;
        long long count2 = 1;
        for(int i = 0; i < k; i ++) {
            count1 *= (total - i);
            count2 *= (i + 1);
        }
        return count1 / count2;
    }
};
