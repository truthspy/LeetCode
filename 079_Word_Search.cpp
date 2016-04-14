class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "")
            return true;
        int m = board.size();
        if(m == 0)
            return false;
        int n = board[0].size();
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(board[i][j] == word[0]) {
                    if(DFS(board, i, j, word, 0, m, n))
                        return true;
                }
            }
        }
        return false;
    }
    bool DFS(vector<vector<char>>& board, int x, int y, string word, int pos, int m, int n) {
        if(pos == word.length())
            return true;
        if(x < 0 || y < 0 || x >= m || y >= n)
            return false;
        if(board[x][y] != word[pos])
            return false;
        board[x][y] = '0';
        if(DFS(board, x + 1, y, word, pos + 1, m, n))
            return true;
        if(DFS(board, x - 1, y, word, pos + 1, m, n))
            return true;
        if(DFS(board, x, y + 1, word, pos + 1, m, n))
            return true;
        if(DFS(board, x, y - 1, word, pos + 1, m, n))
            return true;
        board[x][y] = word[pos];
        return false;
    }
};
