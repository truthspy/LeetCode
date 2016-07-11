class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> solution;
        solve(n, k, result, solution, 1);
        return result;
    }
    void solve(int n, int k, vector<vector<int>>& result, vector<int> solution, int start) {
        if(k == 0) {
            result.push_back(solution);
            return;
        }
        if((n - start + 1) < k)
            return;
        for(int i = start; i <= n; i ++) {
            if((n - i + 1) < k)
                break;
            solution.push_back(i);
            solve(n, k - 1, result, solution, i + 1);
            solution.pop_back();
        }
    }
};
