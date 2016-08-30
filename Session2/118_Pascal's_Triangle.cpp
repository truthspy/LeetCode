class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        if(numRows == 0)
            return res;
        res[0].push_back(1);
        for(int i = 1; i < numRows; i ++) {
            for(int j = 0; j <= i; j ++) {
                int cur = 0;
                if(j == 0 || j == i)
                    cur = 1;
                else
                    cur = res[i - 1][j - 1] + res[i - 1][j];
                res[i].push_back(cur);
            }
        }
        return res;
    }
};
