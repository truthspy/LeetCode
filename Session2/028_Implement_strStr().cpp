class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length();
        int len2 = needle.length();
        for(int i = 0; i <= (len1 - len2); i ++) {
            int j = 0;
            for(; j < len2; j ++) {
                if(haystack[i + j] != needle[j])
                    break;
            }
            if(j == len2)
                return i;
        }
        return -1;
    }
};
