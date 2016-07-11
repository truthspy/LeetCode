/**
 * 思路：只需要考虑最外面一圈的'O'可达范围，不可达的都会变为'X'
 * DFS会爆栈
 * 用BFS/Union Find
 */
struct pos {
    int x;
    int y;
};
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0)
            return;
        int n = board[0].size();
        if(n == 0)
            return;
        for(int i = 0; i < m; i ++) {
            if(board[i][0] == 'O')
                BFS(board, i, 0, m, n);
            if(board[i][n - 1] == 'O')
                BFS(board, i, n - 1, m, n);
        }
        for(int j = 0; j < n; j ++) {
            if(board[0][j] == 'O')
                BFS(board, 0, j, m, n);
            if(board[m - 1][j] == 'O')
                BFS(board, m - 1, j, m, n);
        }
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(board[i][j] == '+')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
    void BFS(vector<vector<char>>& board, int x, int y, int m, int n) {
        int dir[4][2] = {{0,1}, {1,0},{-1,0},{0,-1}};
        queue<pos> reach;
        pos cur;
        cur.x = x;
        cur.y = y;
        reach.push(cur);
        board[cur.x][cur.y] = '+'; 
        while(!reach.empty()) {
            cur = reach.front();
            reach.pop();
            for(int i = 0; i < 4; i ++) {
                pos nextPos;
                nextPos.x = cur.x + dir[i][0];
                nextPos.y = cur.y + dir[i][1];
                if(nextPos.x >= 0 && nextPos.x < m && nextPos.y >= 0 && nextPos.y < n) {
                    if(board[nextPos.x][nextPos.y] == 'O') {
                        reach.push(nextPos);
                        board[nextPos.x][nextPos.y] = '+'; //不能在pop的时候再改，不然会push好多次
                    }
                }
            }
        }
    }

};
