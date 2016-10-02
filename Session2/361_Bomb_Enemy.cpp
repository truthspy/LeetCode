// TODO faster method
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0)
            return 0;
        int m = grid[0].size();
        if(m == 0)
            return 0;
        vector<vector<int>> left(n, vector<int>(m, 0));
        vector<vector<int>> right(n, vector<int>(m, 0));
        vector<vector<int>> up(n, vector<int>(m, 0));
        vector<vector<int>> down(n, vector<int>(m, 0));
        for(int i = 0; i < n; i ++) {
            if(grid[i][0] == 'E')
                left[i][0] = 1;
            for(int j = 1; j < m; j ++) {
                if(grid[i][j] == 'E')
                    left[i][j] = left[i][j - 1] + 1;
                else if(grid[i][j] == '0')
                    left[i][j] = left[i][j - 1];
            }
        }
        for(int i = 0; i < n; i ++) {
            if(grid[i][m - 1] == 'E')
                right[i][m - 1] = 1;
            for(int j = m - 2; j >= 0; j --) {
                if(grid[i][j] == 'E')
                    right[i][j] = right[i][j + 1] + 1;
                else if(grid[i][j] == '0')
                    right[i][j] = right[i][j + 1];
            }
        }
        for(int j = 0; j < m; j ++) {
            if(grid[0][j] == 'E')
                up[0][j] = 1;
            for(int i = 1; i < n; i ++) {
                if(grid[i][j] == 'E')
                    up[i][j] = up[i - 1][j] + 1;
                else if(grid[i][j] == '0')
                    up[i][j] = up[i - 1][j];
            }
        }
        for(int j = 0; j < m; j ++) {
            if(grid[n - 1][j] == 'E')
                down[n - 1][j] = 1;
            for(int i = n - 2; i >= 0; i --) {
                if(grid[i][j] == 'E')
                    down[i][j] = down[i + 1][j] + 1;
                else if(grid[i][j] == '0')
                    down[i][j] = down[i + 1][j];
            }
        }
        int res = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                if(grid[i][j] == '0') {
                    res = max(res, left[i][j] + right[i][j] + up[i][j] + down[i][j]);
                }
            }
        }
        return res;
    }
};
