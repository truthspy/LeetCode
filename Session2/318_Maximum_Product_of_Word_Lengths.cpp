class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> letters(n, 0);
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < words[i].size(); j ++) {
                letters[i] = letters[i] | (1 << (words[i][j] - 'a'));
            }
        }
        int res = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = i + 1; j < n; j ++) {
                if((letters[i] & letters[j]) == 0)
                    res = max(res, (int)words[i].length() * (int)words[j].length());
            }
        }
        return res;
    }
};
