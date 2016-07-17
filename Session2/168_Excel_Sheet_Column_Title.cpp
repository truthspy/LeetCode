class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while(n > 0) {
            int cur = (n - 1) % 26;
            res = (char)('A' + cur) + res;
            n = (n - 1) / 26;
        }
        return res;
    }
};
