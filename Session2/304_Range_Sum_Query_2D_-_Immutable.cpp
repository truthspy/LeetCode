class NumMatrix {
private:
    vector<vector<int>> leftTop;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int row = matrix.size();
        if(row == 0)
            return;
        int col = matrix[0].size();
        for(int i = 0; i < row; i ++) {
            vector<int> cur(col, 0);
            leftTop.push_back(cur);
        }
        leftTop[0][0] = matrix[0][0];
        for(int i = 1; i < col; i ++)
            leftTop[0][i] = leftTop[0][i - 1] + matrix[0][i];
        for(int i = 1; i < row; i ++)
            leftTop[i][0] = leftTop[i - 1][0] + matrix[i][0];
        for(int i = 1; i < row; i ++) {
            for(int j = 1; j < col; j ++) {
                leftTop[i][j] = leftTop[i - 1][j] + leftTop[i][j - 1] + matrix[i][j] - leftTop[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 == 0)
            return leftTop[row2][col2];
        if(row1 == 0)
            return leftTop[row2][col2] - leftTop[row2][col1 - 1];
        if(col2 == 0)
            return leftTop[row2][col2] - leftTop[row1 - 1][col2];
        return leftTop[row2][col2] - leftTop[row2][col1 - 1] - leftTop[row1 - 1][col2] + leftTop[row1 - 1][col1 - 1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
