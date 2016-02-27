/*
思路from discuss
先沿着水平中线翻转，再沿着右对角线翻转
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; i ++) {
            for(int j = 0; j < n; j ++) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }
        for(int i = 0; i < n - 1 ; i ++) {
            for(int j = i + 1; j < n; j ++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
