class Solution {
    
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> nums = {{}, {}, {'a','b','c'}, {'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},
                    {'p','q','r','s'}, {'t','u','v'},{'w','x','y','z'}};
        vector<string> res;
        if(digits.size() == 0)
            return res;
        dfs(0, "", res, digits, nums);
        return res;
    }
    void dfs(int pos, string cur, vector<string> &res, string digits, vector<vector<char>> &nums) {
        if(pos == digits.size())
            res.push_back(cur);
        int dig = digits[pos] - '0';
        for(int i = 0; i < nums[dig].size(); i ++)
            dfs(pos + 1, cur + nums[dig][i], res, digits, nums);
    }
};
