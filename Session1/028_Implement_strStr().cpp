class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length();
        int len2 = needle.length();
        if(len1 < len2)
            return -1;
        int i = 0;
        int j = 0;
        for(i = 0; i < (len1 - len2 + 1); i ++) {
            for(j = 0; j < len2; j ++) {
                if(needle[j] != haystack[i + j])
                    break;
            }
            if(j == len2)
                return i;
        }
        return -1;
    }
};
