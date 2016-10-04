// Another Method: 每一个缩写可以看成是对单词的一个二进制编码，为0的地方还是原来的字母，为1的地方是替换成数字，连续的1要合并
// Another DFS way: 用count记录当前已缩写的字母数，就不需要我这里的last变量记录上一个是不是字母了
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        generate("", 0, word, res, true);
        return res;
    }
    void generate(string cur, int pos, string word, vector<string>& res, bool last) {
        if(pos == word.length()) {
            res.push_back(cur);
            return;
        }
        generate(cur + word[pos], pos + 1, word, res, true);
        if(last) {
            for(int i = 1; i <= (word.length() - pos); i ++)
                generate(cur + to_string(i), pos + i, word, res, false);
        }
    }
};
