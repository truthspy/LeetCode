// TODO 复习！树状数组 自己再写一遍！！
// 初始化成+1的数组大小，可以简化代码，少去多次判断边界条件
class NumMatrix {
private:
    vector<vector<int>> nums;
    vector<vector<int>> tree;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int row = matrix.size();
        if(row == 0)
            return;
        int col = matrix[0].size();
        tree.resize(row + 1, vector<int>(col + 1, 0));
        nums.resize(row + 1, vector<int>(col + 1, 0));
        for(int i = 0; i < row; i ++) {
            for(int j = 0; j < col; j ++)
                update(i, j, matrix[i][j]);
        }
    }

    void update(int row, int col, int val) {
        int diff =  val - nums[row + 1][col + 1];
        for(int i = row + 1; i < tree.size(); i += (i & -i)) {
            for(int j = col + 1; j < tree[0].size(); j += (j & -j)) {
                tree[i][j] += diff;
            }
        }
        nums[row + 1][col + 1] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2, col2) - getSum(row1 - 1, col2) - getSum(row2, col1 - 1) + getSum(row1 - 1, col1 - 1);
    }
    
    int getSum(int row, int col) {
        int res = 0;
        for(int i = row + 1; i > 0; i -= (i & -i)) {
            for(int j = col + 1; j > 0; j -= (j & -j)) {
                res += tree[i][j];
            }
        }
        return res;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
