class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> currentRow;
        for(int i = 1; i <= numRows; i ++) {
            if(i == 1) {
                currentRow.push_back(1);
                result.push_back(currentRow);
                currentRow.clear();
            }
            else {
                currentRow.push_back(1);
                for(int j = 1; j < i - 1; j ++) {
                    int tmp = result[i - 2][j - 1] + result[i - 2][j];
                    currentRow.push_back(tmp);
                }
                currentRow.push_back(result[i - 2][i - 2]);
                result.push_back(currentRow);
                currentRow.clear();
            }
        }
        return result;
    }
};
