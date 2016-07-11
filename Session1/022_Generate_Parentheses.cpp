class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(result, 0, n, "");
        return result;
    }
    void generate(vector<string>& result, int in, int out, string curResult) {
        if(in == 0 && out == 0)
            result.push_back(curResult);
        if(in != 0)
            generate(result, in - 1, out, curResult + ")");
        if(out != 0)
            generate(result, in + 1, out - 1, curResult + "(");
    }
};
