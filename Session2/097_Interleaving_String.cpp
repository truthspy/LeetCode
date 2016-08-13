class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if((len1 + len2) != len3)
            return false;
        vector<vector<bool>> inter(len1 + 1, vector<bool>(len2 + 1, false));
        inter[0][0] = true;
        for(int i = 1; i <= len1; i ++) {
            inter[i][0] = inter[i - 1][0] && (s1[i - 1] == s3[i - 1]);
            if(!inter[i][0])
                break;
        }
        for(int i = 1; i <= len2; i ++) {
            inter[0][i] = inter[0][i - 1] && (s2[i - 1] == s3[i - 1]);
            if(!inter[0][i])
                break;
        }
        for(int i = 1; i <= len1; i ++) {
            for(int j = 1; j <= len2; j ++) {
                if(s3[i + j - 1] == s1[i - 1])
                    inter[i][j] = inter[i - 1][j];
                if(!inter[i][j] && s3[i + j - 1] == s2[j - 1])
                    inter[i][j] = inter[i][j - 1];
            }
        }
        return inter[len1][len2];
    }
};
