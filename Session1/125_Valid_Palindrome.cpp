class Solution {
public:
    bool isAlphaNum(char c) {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            return true;
        if(c >= '0' && c <= '9')
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i <= j) {
            while(i <= j && (!isAlphaNum(s[i])))
                i ++;
            while(i <= j && (!isAlphaNum(s[j])))
                j --;
            if(i > j)
                break;
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] - 'A' + 'a';
            if(s[j] >= 'A' && s[j] <= 'Z')
                s[j] = s[j] - 'A' + 'a';
            if(s[i] != s[j])
                return false;
            i ++;
            j --;
        }
        return true;
    }
};
