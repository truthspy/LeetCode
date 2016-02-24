class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {0};
        bool col[9][9] = {0};
        bool box[3][3][9] = {0};
        for(int i = 0; i < 9; i ++) {
            for(int j = 0; j < 9; j ++) {
                if(board[i][j] != '.') {
                    int tmp = board[i][j] - '1';
                    if(row[i][tmp] || col[j][tmp] || box[i/3][j/3][tmp])
                        return false;
                    row[i][tmp] = true;
                    col[j][tmp] = true;
                    box[i/3][j/3][tmp] = true;
                }
            }
        }
        return true;
    }
};
