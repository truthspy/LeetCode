class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        int len = s.size();
        for(int i = 0; i < len - 1; i ++) {
            if(s[i] == '+' && s[i + 1] == '+') {
                s[i] = '-';
                s[i + 1] = '-';
                result.push_back(s);
                s[i] = '+';
                s[i + 1] = '+';
            }
        }
        return result;
    }
};