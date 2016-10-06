class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        if(n == 0)
            return;
        int m = board[0].size();
        if(m == 0)
            return;
        int dir[8][2] = {{0,1}, {0,-1}, {1, 0}, {-1,0}, {-1,-1}, {1, 1}, {-1,1}, {1, -1}};
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                int count = 0;
                for(int k = 0; k < 8; k ++) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if(x >= 0 && x < n && y >= 0 && y < m)
                        if((board[x][y] & 1) == 1)
                            count ++;
                }
                if(count == 3 || (count == 2 && board[i][j] == 1))
                    board[i][j] = (board[i][j] | 2);
            }
        }
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++)
                board[i][j] = board[i][j] >> 1;
        }
    }
};
