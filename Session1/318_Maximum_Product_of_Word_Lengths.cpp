class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> wordBit(n, 0);
        int maxVal = 0;
        for(int i = 0; i < n; i ++) {
            int len = words[i].length();
            for(int j = 0; j < len; j ++) {
                int pos = words[i][j] - 'a';
                wordBit[i] = (wordBit[i] | (1 << pos));
            }
            for(int j = 0; j < i; j ++) {
                if((wordBit[i] & wordBit[j]) == 0) {
                    int len1 = words[i].length();
                    int len2 = words[j].length();
                    maxVal = max(maxVal, len1 * len2);
                }
            }
        }
        return maxVal;
    }
};
