class Solution {
public:
    string reverseVowels(string s) {
        int l = 0;
        int r = s.length() - 1;
        while(l < r) {
            if(isVowels(s[l]) && isVowels(s[r])) {
                char tmp = s[l];
                s[l] = s[r];
                s[r] = tmp;
                l ++;
                r --;
            }
            else if(!isVowels(s[l]))
                l ++;
            else
                r --;
        }
        return s;
    }
    bool isVowels(char a) {
        if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
            return true;
        if(a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
            return true;
        return false;
    }
};
