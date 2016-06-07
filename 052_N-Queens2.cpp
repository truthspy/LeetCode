class Solution {
public:
    int totalNQueens(int n) {
        if(n == 0 || n == 1)
            return n;
        vector<vector<bool>> board(n, vector<bool>(n, false));
        int result = 0;
        putQueens(board, 0, result);
        return result;
    }
    bool judge(vector<vector<bool>> &board, int row, int col) {
        for(int i = 0; i < row; i ++)
            if(board[i][col])
                return false;
        int i = row - 1;
        int j = col - 1;
        while(i >= 0 && j >= 0) {
            if(board[i][j])
                return false;
            
            i --;
            j --;
        }
        i = row - 1;
        int k = col + 1;
        while(i >= 0 && k < board.size()) {
            if(board[i][k])
                return false;
            i --;
            k ++;
        }
        return true;
    }
    void putQueens(vector<vector<bool>> &board, int row, int &result) {
        int n = board.size();
        if(row == n)
            result ++;
        for(int col = 0; col < n; col ++) {
            if(judge(board, row, col)) {
                board[row][col] = true;
                putQueens(board, row + 1, result);
                board[row][col] = false;
            }
        }
    }
};
