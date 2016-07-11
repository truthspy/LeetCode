class Solution {
public:
    void reverseWords(string &s) {
        int len = s.length();
        string result = "";
        int r = len - 1;
        int l = r;
        while(l >= 0) {
            while(r >= 0 && s[r] == ' ')
                r --;
            l = r;
            while(l >= 0 && s[l] != ' ')
                l --;
            for(int i = l + 1; i <= r; i ++)
                result += s[i];
            if(l < r)
                result += ' ';
            r = l;
        }
        s = result.substr(0, result.length() - 1);
    }
};

//TODO
//O(1) space solution
