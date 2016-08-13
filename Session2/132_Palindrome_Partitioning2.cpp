class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        vector<vector<bool>> isPalindrome(len, vector<bool>(len, false));
        for(int i = 0; i < len; i ++)
            isPalindrome[i][i] = true;
        
        /*可以合并到循环里做，减少时间
        for(int l = 1; l < len; l ++) {
            for(int i = 0; i < len - l; i ++) {
                int j = i + l;
                isPalindrome[i][j] = (s[i] == s[j]);
                if(isPalindrome[i][j] && j - i > 1)
                    isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
            }
        }*/
        
        vector<int> cut(len, INT_MAX);
        cut[0] = 0;
        int i = 1;
        while(i < len) {
            for(int j = i; j >= 0; j --) {
                if(s[i] == s[j] && (i - j <= 1 || isPalindrome[j + 1][i - 1])) {
                    isPalindrome[j][i] = true;
                    if(j == 0)
                        cut[i] = 0;
                    else
                        cut[i] = min(cut[i], cut[j - 1] + 1);
                }
            }
            i ++;
        }
        return cut[len - 1];
    }
};
