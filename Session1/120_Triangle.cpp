class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        vector<int> bottomMax(size, 0);
        for(int i = size - 1; i > 0; i --) {
            for(int j = 0; j < i; j ++) {
                bottomMax[j] = min(triangle[i][j] + bottomMax[j], triangle[i][j + 1] + bottomMax[j + 1]);
            }
        }
        return bottomMax[0] + triangle[0][0];
    }
};
