class Solution {
public:
    string reverseString(string s) {
        int l = 0;
        int r = s.length() - 1;
        while(l < r) {
            int tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l ++;
            r --;
        }
        return s;
    }
};
