class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        int record[26] = {0};
        int len = s.length();
        for(int i = 0; i < len; i ++) {
            record[s[i] - 'a'] ++;
        }
        for(int i = 0; i < len; i ++) {
            int pos = t[i] - 'a';
            record[pos] --;
            if(record[pos] < 0)
                return false;
        }
        return true;
    }
};
