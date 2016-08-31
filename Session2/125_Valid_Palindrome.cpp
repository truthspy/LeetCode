class Solution {
public:
    bool isAlphaNum(char a) {
        if(a <= 'z' && a >= 'a')
            return true;
        if(a <= 'Z' && a >= 'A')
            return true;
        if(a >= '0' && a <= '9')
            return true;
        return false;
    }
    char toLower(char a) {
        if(a >= 'A' && a <= 'Z')
            a = 'a' + a - 'A';
        return a;
    }
    bool isPalindrome(string s) {
        if(s == "")
            return true;
        int i = 0;
        int j = s.length() - 1;
        while(i < j) {
            while(i < j && !isAlphaNum(s[i]))
                i ++;
            while(i < j && !isAlphaNum(s[j]))
                j --;
            if(i < j && toLower(s[i]) != toLower(s[j]))
                return false;
            i ++;
            j --;
        }
        return true;
    }
};
