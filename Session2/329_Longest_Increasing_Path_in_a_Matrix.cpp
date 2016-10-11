// 因为递增路径肯定是一个小于另一个，所以不需要visited数组
// 不用map再进行pos的转换，直接建立二维数组就行
class Solution {
private:
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    // unordered_map<int, int> mp;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0)
            return 0;
        int m = matrix[0].size();
        if(m == 0)
            return 0;
        int res = 0;
        vector<vector<int>> mp(n, vector<int>(m, -1));
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                // vector<vector<bool>> visited(n, vector<bool>(m, false));
                // res = max(res, dfs(i * m + j, m, n, visited, matrix));
                res = max(res, dfs(i, j, mp, matrix, n, m));
            }
        }
        return res;
    }
    // int dfs(int pos, int m, int n, vector<vector<bool>> visited, vector<vector<int>>& matrix) {
    int dfs(int x, int y, vector<vector<int>>& mp, vector<vector<int>>& matrix, int n, int m) {
        // if(mp.find(pos) != mp.end())
        //     return mp[pos];
        // int x = pos / m;
        // int y = pos % m;
        // visited[x][y] = true;
        if(mp[x][y] != -1)
            return mp[x][y];
        int res = 1;
        for(int i = 0; i < 4; i ++) {
            int nextX = x + dir[i][0];
            int nextY = y + dir[i][1];
            if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
                if(matrix[x][y] < matrix[nextX][nextY])
                    res = max(res, dfs(nextX, nextY, mp, matrix, n, m) + 1);
            }
        }
        // visited[x][y] = false;
        // mp[pos] = res;
        mp[x][y] = res;
        return res;
    }
};
