class NumMatrix {
public:
    vector<vector<int>> leftUp;
    NumMatrix(vector<vector<int>> &matrix) {
        int row = matrix.size();
        if(row > 0) {
            int col = matrix[0].size();
            for(int i = 0; i < row; i ++) {
                leftUp.push_back(vector<int>(col, 0));
            }
            leftUp[0][0] = matrix[0][0];
            for(int i = 1; i < row; i ++)
                leftUp[i][0] = leftUp[i - 1][0] + matrix[i][0];
            for(int j = 1; j < col; j ++)
                leftUp[0][j] = leftUp[0][j - 1] + matrix[0][j];
            for(int i = 1; i < row; i ++) {
                for(int j = 1; j < col; j ++) {
                    leftUp[i][j] = matrix[i][j] + leftUp[i][j - 1] + leftUp[i - 1][j] - leftUp[i - 1][j - 1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(leftUp.size() == 0)
            return 0;
        if(row1 == 0 && col1 == 0)
            return leftUp[row2][col2];
        if(row1 == 0)
            return leftUp[row2][col2] - leftUp[row2][col1 - 1];
        if(col1 == 0)
            return leftUp[row2][col2] - leftUp[row1 - 1][col2];
        return leftUp[row2][col2] - leftUp[row2][col1 - 1] - leftUp[row1 - 1][col2] + leftUp[row1 - 1][col1 - 1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
