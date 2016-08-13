class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> pathSum(n, 0);
        if(n == 0)
            return 0;
        pathSum[0] = triangle[0][0];
        for(int i = 1; i < n; i ++) {
            /* 这样会导致pathSum[i - 1]取的是同一行的数
            初始化0不能直接加，因为存在负数。
            pathSum[0] = pathSum[0] + triangle[i][0];
            for(int j = 1; j <= i; j ++) {
                pathSum[j] = min(pathSum[j - 1], pathSum[j]) + triangle[i][j];
            }
            */
            pathSum[i] = pathSum[i - 1] + triangle[i][i];
            for(int j = i - 1; j >= 1; j --)
                pathSum[j] = min(pathSum[j - 1], pathSum[j]) + triangle[i][j];
            pathSum[0] = pathSum[0] + triangle[i][0];
        }
        int minPath = INT_MAX;
        for(int i = 0; i < n; i ++)
            minPath = min(minPath, pathSum[i]);
        return minPath;
    }
};
