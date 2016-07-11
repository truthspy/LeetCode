//比较慢
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();
        int i = -1;
        int j = -1;
        for(; i < m - 1; i ++) {
            if(target == matrix[i + 1][0])
                return true;
            if(target < matrix[i + 1][0])
                break;
        }
        if(i == -1)
            return false;
        for(; j < n - 1; j ++) {
            if(target == matrix[i][j + 1])
                return true;
            if(target < matrix[i][j + 1])
                return false;
        }
        return false;
    }
};

//看成一维，二分查找，较快
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();
        int l = m * n;
        int start = 0;
        int end = l - 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            int val = matrix[mid / n][mid % n];
            if(val == target)
                return true;
            if(val < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return matrix[start / n][start % n] == target;
    }
};
