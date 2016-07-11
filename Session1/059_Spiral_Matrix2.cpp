class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int istep[4] = {0, 1, 0, -1};
        int jstep[4] = {1, 0, -1, 0};
        int num = 1;
        int square = n * n;
        int i = 0;
        int j = 0;
        while(n > 0) {
            if(n == 1) {
                result[i][j] = num;
                break;
            }
            for(int m = 0; m < 4; m ++) {
                for(int k = 0; k < n - 1; k ++) {
                    result[i][j] = num;
                    if(num == square)
                        return result;
                    num ++;
                    if(m == 3 && k == n - 2) {
                        i += istep[0];
                        j += jstep[0];
                    }
                    else {
                        i += istep[m];
                        j += jstep[m];
                    }
                }
            }
            n -= 2;
        }
        return result;
    }
};
