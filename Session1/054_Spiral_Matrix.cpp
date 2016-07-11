class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        if(m == 0)
            return result;
        int n = matrix[0].size();
        int startX = 0;
        int startY = 0;
        while(m > 0 && n > 0) {
            if(m == 1) {
                for(int i = 0; i < n; i ++)
                    result.push_back(matrix[startX][startY + i]);
                break;
            }
            if(n == 1) {
                for(int i = 0; i < m; i ++)
                    result.push_back(matrix[startX + i][startY]);
                break;
            }
            for(int i = 0; i < n - 1; i ++)
                result.push_back(matrix[startX][startY + i]);
            for(int i = 0; i < m - 1; i ++)
                result.push_back(matrix[startX + i][startY + n - 1]);
            for(int i = 0; i < n - 1; i ++)
                result.push_back(matrix[startX + m - 1][startY + n - 1 - i]);
            for(int i = 0; i < m - 1; i ++)
                result.push_back(matrix[startX + m - 1 - i][startY]);
            startX ++;
            startY ++;
            m -= 2;
            n -= 2;
        }
        return result;
    }
};
