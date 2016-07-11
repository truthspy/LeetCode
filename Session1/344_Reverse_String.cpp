class Solution {
public:
    string reverseString(string s) {
        int len = s.length();
        int l = 0;
        int r = len - 1;
        while(l < r) {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l ++;
            r --;
        }
        return s;
    }
};
