class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0)
            return 0;
        int n = grid[0].size();
        int count = 0;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(grid[i][j] != '0') {
                    mark(grid, i, j);
                    count ++;
                }
            }
        }
        return count;
    }
    void mark(vector<vector<char>>& grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();
        if(x < 0 || y < 0 || x >= m || y >= n)
            return;
        if(grid[x][y] == '0')
            return;
        grid[x][y] = '0';
        mark(grid, x - 1, y);
        mark(grid, x + 1, y);
        mark(grid, x, y - 1);
        mark(grid, x, y + 1);
    }
};
