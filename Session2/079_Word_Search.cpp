class Solution {
    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "")
            return true;
        int n = board.size();
        if(n == 0)
            return false;
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                if(ifExist(i, j, 0, word, visited, board))
                    return true;
            }
        }
        return false;
    }
    bool ifExist(int x, int y, int pos, string word, vector<vector<bool>>& visited,vector<vector<char>>& board) {
        if(pos == word.size())
            return true;
        int n = board.size();
        int m = board[0].size();
        if(x < 0 || y < 0 || x >= n || y >= m)
            return false;
        if(visited[x][y])
            return false;
        if(board[x][y] == word[pos]) {
            visited[x][y] = true;
            for(int i = 0; i < 4; i ++) {
                if(ifExist(x + dir[i][0], y + dir[i][1], pos + 1, word, visited, board)) {
                    visited[x][y] = false;
                    return true;
                }
            }
            visited[x][y] = false;
        }
        return false;
    }
};
