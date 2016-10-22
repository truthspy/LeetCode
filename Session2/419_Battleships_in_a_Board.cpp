class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0)
            return 0;
        int m = board[0].size();
        if(m == 0)
            return 0;
        int res = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                if(board[i][j] == '.')
                    continue;
                if(i > 0 && board[i - 1][j] == 'X')
                    continue;
                if(j > 0 && board[i][j - 1] == 'X')
                    continue;
                res ++;
            }
        }
        return res;
    }
};
