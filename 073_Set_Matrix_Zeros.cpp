//O(m + n)空间复杂度的方法
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return;
        int n = matrix[0].size();
        vector<bool> mFlag(m, 0);
        vector<bool> nFlag(n, 0);

        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(matrix[i][j] == 0) {
                    mFlag[i] = 1;
                    nFlag[j] = 1;
                }
            }
        }
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(mFlag[i] || nFlag[j])
                    matrix[i][j] = 0;
            }
        }
    }
};

//O(1)空间复杂度的方法
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return;
        int n = matrix[0].size();
        int col0 = 1;
        for(int i = 0; i < m; i ++) {
            if(matrix[i][0] == 0)
                col0 = 0;
            for(int j = 1; j < n; j ++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = m - 1; i >= 0; i --) {
            for(int j = n - 1; j > 0; j --) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if(col0 == 0)
                matrix[i][0] = 0;
        }
    }
};
