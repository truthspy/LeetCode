class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;
        int j = 0;
        int wordLen = word.length();
        int abbrLen = abbr.length();
        while(i < wordLen && j < abbrLen) {
            if(abbr[j] >= 'a' && abbr[j] <= 'z') {
                if(abbr[j] != word[i])
                    return false;
                i ++;
                j ++;
                continue;
            }
            // 要考虑abbr中出现0的情况！
            if(abbr[j] == '0')
                return false;
            int count = abbr[j] - '0';
            j ++;
            while(j < abbrLen && abbr[j] >= '0' && abbr[j] <= '9') {
                count = count * 10 + abbr[j] - '0';
                j ++;
            }
            i += count;
        }
        return (i == wordLen && j == abbrLen);
    }
};
