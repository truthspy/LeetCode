//空间复杂度比较高
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(m == 0)
            return;
        int n = board[0].size();
        vector<vector<int>> count(m, vector<int>(n, 0));
        int xstep[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int ystep[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(board[i][j] == 1) {
                    for(int k = 0; k < 8; k ++) {
                        int x = i + xstep[k];
                        int y = j + ystep[k];
                        if(x >= 0 && x < m && y >= 0 && y < n)
                            count[x][y] ++;
                    }
                }
            }
        }
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(board[i][j] == 1) {
                    if(count[i][j] < 2 || count[i][j] > 3)
                        board[i][j] = 0;
                }
                else {
                    if(count[i][j] == 3)
                        board[i][j] = 1;
                }
            }
        }
    }
};

//Todo
//可以借助bit,每一个位置用两个比特表示,
//低位代表元素值，高位代表下一代的值
//计算周围live的数目时，可以通过获取低位的值得到
