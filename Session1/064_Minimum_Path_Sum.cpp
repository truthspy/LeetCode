//空间复杂度高，可压缩空间
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> sum(m, vector<int>(n,0));
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(i == 0 && j == 0)
                    sum[i][j] = grid[i][j];
                else if(i == 0)
                    sum[i][j] = sum[i][j - 1] + grid[i][j];
                else if(j == 0)
                    sum[i][j] = sum[i - 1][j] + grid[i][j];
                else
                    sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
            }
        }
        return sum[m - 1][n - 1];
    }
};

//压缩成一维数组的算法
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> sum(n, 0);
        sum[0] = grid[0][0];
        for(int i = 1; i < n; i ++)
            sum[i] = sum[i - 1] + grid[0][i];
        for(int i = 1; i < m; i ++) {
            sum[0] = sum[0] + grid[i][0];
            for(int j = 1; j < n; j ++)
                sum[j] = min(sum[j - 1], sum[j]) + grid[i][j];
        }
        return sum[n - 1];
    }
};
