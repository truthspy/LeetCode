// Follow-Up: o(1)空间
// 可以先保存第一行第一列的状态，然后把下面代码里的row&col数组记录在第一行和第一列的位置
// 最后再跟进保存的第一行第一列的状态恢复第一行第一列的结果

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0)
            return;
        int m = matrix[0].size();
        if(m == 0)
            return;
        vector<bool> row(n, false);
        vector<bool> col(m, false);
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                if(matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                if(row[i] || col[j])
                    matrix[i][j] = 0;
            }
        }
    }
};
