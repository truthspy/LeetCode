/**
 * T中会出现重复字符，要找的子串中必须包含同样的重复字符，而不是只出现一次就行
 */
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hashTable;
        unordered_map<char,int> exNum;
        int num = t.length();
        for(int i = 0; i < t.length(); i ++) {
            if(hashTable.find(t[i]) == hashTable.end()) {
                hashTable[t[i]] = 0;
                exNum[t[i]] = 0;
            }
            exNum[t[i]] ++;
        }
        int l = 0;
        int r = 0;
        int sLen = s.length();
        int count = 0;
        int minLen = sLen + 1;
        int L = -1;
        while(l < sLen && r < sLen) {
            while(count != num && r < sLen) {
                if(hashTable.find(s[r]) != hashTable.end()) {
                    if(hashTable[s[r]] < exNum[s[r]]) {
                        count ++;
                    }
                    hashTable[s[r]] ++;
                }
                r ++;
            }
            while(count == num && l < r) {
                int curLen = r - l;
                if(curLen < minLen) {
                    minLen = curLen;
                    L = l;
                }
                if(l < r && hashTable.find(s[l]) != hashTable.end()) {
                    hashTable[s[l]] --;
                    if(hashTable[s[l]] < exNum[s[l]])
                        count --;
                }
                l ++;
            }
        }
        if(minLen == (sLen + 1))
            return "";
        return s.substr(L, minLen);
    }
};
