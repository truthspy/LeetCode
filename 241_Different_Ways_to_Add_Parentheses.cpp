/**
 * from discuss
 */
/**
 * Method1: 递归
 * 优化：可以用一个map<string, vector<int>>记录中间结果
 * Method2: 动归，看着好麻烦没有仔细看
 */
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int len = input.length();
        for(int i = 0; i < len; i ++) {
            if(input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> res1 = diffWaysToCompute(input.substr(0, i));   //不是i-1
                vector<int> res2 = diffWaysToCompute(input.substr(i + 1));  //只有一个参数时默认到结尾
                int size1 = res1.size();
                int size2 = res2.size();
                for(int j = 0; j < size1; j ++) {
                    for(int k = 0; k < size2; k ++) {
                        if(input[i] == '+')
                            res.push_back(res1[j] + res2[k]);
                        else if(input[i] == '-')
                            res.push_back(res1[j] - res2[k]);
                        else
                            res.push_back(res1[j] * res2[k]);
                    }
                }
            }
        }
        if(res.empty()) {
            res.push_back(stoi(input));
        }
        return res;
    }
};
