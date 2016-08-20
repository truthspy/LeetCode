class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0)
            return 0;
        int m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                if(grid[i][j] == '1') {
                    count ++;
                    markGrid(grid, i, j, m, n);
                }
            }
        }
        return count;
    }
    void markGrid(vector<vector<char>>& grid, int x, int y, int m, int n) {
        if(x < 0 || y < 0 || x >= n || y >= m)
            return;
        if(grid[x][y] == '0')
            return;
        grid[x][y] = '0';
        markGrid(grid, x + 1, y, m, n);
        markGrid(grid, x - 1, y, m, n);
        markGrid(grid, x, y + 1, m, n);
        markGrid(grid, x, y - 1, m, n);
    }
};
