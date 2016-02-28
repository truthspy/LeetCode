//较慢的动归方法
class Solution {
public:
    int numSquares(int n) {
        vector<int> minNum(n + 1, INT_MAX);
        for(int i = 1; i < n + 1; i ++) {
            int root = sqrt(i);
            if(root * root == i)
                minNum[i] = 1;
            else {
                // int mid = i / 2 + 1;
                // for(int j = 1; j <= mid; j ++) {
                //     minNum[i] = min(minNum[i], minNum[j] + minNum[i - j]);
                // }这个复杂度太高，会超时
                // 下面这个省时
                // i肯定是由某个完全平方数l=j*j，与(i - j*j)的和组成
                // 只需要遍历1到j即可
                for(int j = 1; j <= root; j ++) {
                    minNum[i] = min(minNum[i], 1 + minNum[i - j*j]);
                }
            }
        }
        return minNum[n];
    }
};

