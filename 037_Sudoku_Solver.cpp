class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(10, false));
        vector<vector<bool>> col(9, vector<bool>(10, false));
        vector<vector<bool>> square(9, vector<bool>(10, false));
        for(int i = 0; i < 9; i ++) {
            for(int j = 0; j < 9; j ++) {
                if(board[i][j] != '.') {
                    int cur = board[i][j] - '0';
                    row[i][cur] = true;
                    col[j][cur] = true;
                    int pos = i / 3 * 3 + j / 3;
                    square[pos][cur] = true;
                }
            }
        }
        solve(row, col, square, board, 0);
    }
    bool solve(vector<vector<bool>> &row, vector<vector<bool>> &col, vector<vector<bool>> &square, vector<vector<char>>& board, int pos) {
        if(pos == 81)
            return true;
        int i = pos / 9;
        int j = pos % 9;
        if(board[i][j] != '.') {
            if(solve(row, col, square, board, pos + 1))
                return true;
            return false;
        }
        int unit = i / 3 * 3 + j / 3;
        for(int k = 1; k <= 9; k ++) {
            if(!row[i][k] && !col[j][k] && !square[unit][k]) {
                board[i][j] = k + '0';
                row[i][k] = true;
                col[j][k] = true;
                square[unit][k] = true;
                if(solve(row, col, square, board, pos + 1))
                    return true;
                board[i][j] = '.';
                row[i][k] = false;
                col[j][k] = false;
                square[unit][k] = false;
            }
        }
        return false;
    }
};
