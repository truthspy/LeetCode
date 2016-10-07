class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur = "";
        dfs(0, 0, n, cur, res);
        return res;
    }
    void dfs(int left, int right, int n, string cur, vector<string>& res) {
        if(left == n && right == n) {
            res.push_back(cur);
            return;
        }
        if(left > n || right > n || right > left)
            return;
        dfs(left + 1, right, n, cur + "(", res);
        dfs(left, right + 1, n, cur + ")", res);
    }
};
