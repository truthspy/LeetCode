class Solution {
public:
    string reverseVowels(string s) {
        int l = 0;
        int r = s.length() - 1;
        while(l < r) {
            while(l < r && !ifVowels(s[l]))
                l ++;
            while(l < r && !ifVowels(s[r]))
                r --;
            if(l < r) {
                char tmp = s[l];
                s[l] = s[r];
                s[r] = tmp;
                l ++;
                r --;
            }
        }
        return s;
    }
    bool ifVowels(char a) {
        if(a == 'a' || a == 'A')
            return true;
        if(a == 'e' || a == 'E')
            return true;
        if(a == 'i' || a == 'I')
            return true;
        if(a == 'o' || a == 'O')
            return true;
        if(a == 'u' || a == 'U')
            return true;
        return false;
    }
};
