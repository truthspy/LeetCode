// TODO:不用额外空间
// 直接限定遍历的左边界和右边界就可以
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if(m == 0)
            return res;
        int n = matrix[0].size();
        if(n == 0)
            return res;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int i = 0, j = 0;
        while(true) {
            if(visited[i][j])
                break;
            while(j < n && visited[i][j] == false) {
                visited[i][j] = true;
                res.push_back(matrix[i][j]);
                j ++;
            }
            j --; i ++;
            if(i == m || visited[i][j])
                break;
            while(i < m && visited[i][j] == false) {
                visited[i][j] = true;
                res.push_back(matrix[i][j]);
                i ++;
            }
            i --; j --;
            if(j < 0 || visited[i][j])
                break;
            while(j >= 0 && visited[i][j] == false) {
                visited[i][j] = true;
                res.push_back(matrix[i][j]);
                j --;
            }
            j ++; i --;
            if(i < 0 || visited[i][j])
                break;
            while(i >= 0 && visited[i][j] == false) {
                visited[i][j] = true;
                res.push_back(matrix[i][j]);
                i --;
            }
            i ++; j ++;
        }
        return res;
    }
};
