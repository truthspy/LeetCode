// 思路from http://www.cnblogs.com/grandyang/p/5467118.html
// 如果玩家1在第一行某一列放了一个子，那么rows[0]自增1，如果玩家2在第一行某一列放了一个子，则rows[0]自减1，那么只有当rows[0]等于n或者-n的时候，表示第一行的子都是一个玩家放的，则游戏结束返回该玩家即可，其他各行各列，对角线和逆对角线都是这种思路
class TicTacToe {
private:
    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int anti_diagonal;
    int size;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows.resize(n, 0);
        cols.resize(n, 0);
        diagonal = 0;
        anti_diagonal = 0;
        size = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(player == 1) {
            rows[row] ++;
            cols[col] ++;
            if(row == col)
                diagonal ++;
            //不能用else，最中间的那个既在对角线上，也在反对角线上
            if(row + col == size - 1)
                anti_diagonal ++;
        }
        else {
            rows[row] --;
            cols[col] --;
            if(row == col)
                diagonal --;
            if(row + col == (size - 1))
                anti_diagonal --;
        }
        if(rows[row] == size || cols[col] == size || diagonal == size || anti_diagonal == size)
            return player;
        if(rows[row] == -size || cols[col] == -size || diagonal == -size || anti_diagonal == -size)
            return player;
        return 0;
    }
};
/*
class TicTacToe {
private:
    vector<vector<int>> board;
    int size;
public:
    TicTacToe(int n) {
        size = n;
        board.resize(n, vector<int>(n, 0));
    }
    int move(int row, int col, int player) {
        board[row][col] = player;
        bool flag = true;
        if(row == col) {
            for(int i = 0; i < size; i ++) {
                if(board[i][i] != player) {
                    flag = false;
                    break;
                }
            }
            if(flag)
                return player;
        }
        // 还有反对角线。。
        flag = true;
        if(row + col == size - 1) {
            for(int i = 0; i < size; i ++) {
                if(board[i][size - 1 - i] != player) {
                    flag = false;
                    break;
                }
            }
            if(flag)
                return player;
        }
        flag = true;
        for(int i = 0; i < size; i ++) {
            if(board[row][i] != player) {
                flag = false;
                break;
            }
        }
        if(flag)
            return player;
        flag = true;
        for(int i = 0; i < size; i ++) {
            if(board[i][col] != player) {
                flag = false;
                break;
            }
        }
        if(flag)
            return player;
        return 0;
    }
};
 */
/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
