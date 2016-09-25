class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int res = 0;
        int sum = 0;
        int n = A.size();
        for(int i = 0; i < n; i ++) {
            sum += A[i];
            res += (i * A[i]);
        }
        int maxRes = res;
        for(int i = 1; i < n; i ++) {
            res = res + sum - n * A[n - i];
            maxRes = max(maxRes, res);
        }
        return maxRes;
    }
};
