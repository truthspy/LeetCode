class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        int col = 0;
        for(int i = 0; i < len; i ++) {
            col += (s[i] - 'A' + 1) * pow(26, len - i - 1);
        }
        return col;
    }
};
