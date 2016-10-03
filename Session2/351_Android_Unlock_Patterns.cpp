// 1、3、7、9对称，只遍历一个就行，同理2、4、6、8对称，也只需遍历一个，再遍历一个5
// 提前用数组记录中间需要跳过的情况
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> jump(10, vector<int>(10, 0));
        jump[1][3] = jump[3][1] = 2;
        jump[1][7] = jump[7][1] = 4;
        jump[1][9] = jump[9][1] = 5;
        jump[2][8] = jump[8][2] = 5;
        jump[3][9] = jump[9][3] = 6;
        jump[3][7] = jump[7][3] = 5;
        jump[4][6] = jump[6][4] = 5;
        jump[7][9] = jump[9][7] = 8;
        vector<bool> visited(10, false);
        visited[0] = true;
        int res1 = 0;
        dfs(1, 1, res1, m, n, visited, jump);
        int res2 = 0;
        dfs(2, 1, res2, m, n, visited, jump);
        int res5 = 0;
        dfs(5, 1, res5, m, n, visited, jump);
        return res1 * 4 + res2 * 4 + res5;
    }
    void dfs(int pos, int len, int &res, int m, int n, vector<bool> &visited, vector<vector<int>> &jump) {
        if(len >= m)
            res ++;
        if(len == n)
            return;
        visited[pos] = true;
        for(int i = 1; i <= 9; i ++) {
            if(visited[i])
                continue;
            if(visited[jump[pos][i]]) {
                // visited[i] = true;
                dfs(i, len + 1, res, m, n, visited, jump);
                // visited[i] = false;
            }
        }
        visited[pos] = false;
    }
};
