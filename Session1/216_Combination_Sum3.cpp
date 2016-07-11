class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> solution;
        if(k > 9 || n > 45)
            return result;
        combination(k, n, result, solution, 1);
        return result;
    }
    void combination(int k, int n, vector<vector<int>>& result, vector<int> solution, int start) {
        if(k == 0 && n == 0)
            result.push_back(solution);
        if(k < 0 || start > n)
            return;
        if(k == 0) //防止后面出现除0的情况！！！！！
            return;
        if(start > n / k || n / k > 9)
            return;
        for(int i = start; i <= 9; i ++) {
            if(i <= n) {
                solution.push_back(i);
                combination(k - 1, n - i, result, solution, i + 1);
                solution.pop_back();
            }
            else
                break;
        }
    }
};
