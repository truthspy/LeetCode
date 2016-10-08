class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0)
            return false;
        int m = matrix[0].size();
        if(m == 0)
            return false;
        int i = n - 1;
        int j = 0;
        while(i >= 0 && j < m) {
            if(matrix[i][j] == target)
                return true;
            if(matrix[i][j] < target)
                j ++;
            else
                i --;
        }
        return false;
    }
};
