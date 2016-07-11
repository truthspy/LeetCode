class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        if(n == 0)
            return result;
        string tmp = "";
        for(int i = 0; i < n; i ++)
            tmp += ".";
        vector<string> board(n, tmp);
        putQueens(board, 0, result);
        return result;
    }
    bool judge(vector<string> &board, int row, int col) {
        for(int i = 0; i < row; i ++)
            if(board[i][col] == 'Q')
                return false;
        int i = row - 1;
        int j = col - 1;
        while(i >= 0 && j >= 0) {
            if(board[i][j] == 'Q')
                return false;
            
            i --;
            j --;
        }
        i = row - 1;
        int k = col + 1;
        while(i >= 0 && k < board.size()) {
            if(board[i][k] == 'Q')
                return false;
            i --;
            k ++;
        }
        return true;
    }
    void putQueens(vector<string> &board, int row, vector<vector<string>> &result) {
        int n = board.size();
        if(row == n)
            result.push_back(board);
        for(int col = 0; col < n; col ++) {
            if(judge(board, row, col)) {
                board[row][col] = 'Q';
                putQueens(board, row + 1, result);
                board[row][col] = '.';
            }
        }
    }
};
