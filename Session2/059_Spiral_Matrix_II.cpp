class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int num = 1;
        int start = 0;
        int end = n - 1;
        while(start <= end) {
            for(int i = start; i <= end; i ++) {
                matrix[start][i] = num;
                num ++;
            }
            for(int i = start + 1; i <= end; i ++) {
                matrix[i][end] = num;
                num ++;
            }
            for(int i = end - 1; i >= start; i --) {
                matrix[end][i] = num;
                num ++;
            }
            for(int i = end - 1; i > start; i --) {
                matrix[i][start] = num;
                num ++;
            }
            start ++;
            end --;
        }
        return matrix;
    }
};
