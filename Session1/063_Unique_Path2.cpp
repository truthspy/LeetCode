class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        vector<int> pathNum(n, 0);
        pathNum[0] = 1;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(obstacleGrid[i][j] == 1)
                    pathNum[j] = 0;
                else if(j != 0)
                    pathNum[j] = pathNum[j - 1] + pathNum[j];
            }
        }
        return pathNum[n - 1];
    }
};
