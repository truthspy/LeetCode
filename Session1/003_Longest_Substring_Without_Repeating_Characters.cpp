//My solution
//遇到重复字符时，移去队头的字符，继续搜索
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_set<char> hash;
        int len = s.length();
        int i = 0;
        while(i < len && hash.find(s[i]) == hash.end()) {
            hash.insert(s[i]);
            i ++;
        }
        if(i == len)
            return len;
        maxLen = max(maxLen, i);
        for(int j = 0 ; j < len; j ++) {
            hash.erase(s[j]);
            while(i < len && hash.find(s[i]) == hash.end()) {
                hash.insert(s[i]);
                i ++;
            }
            maxLen = max(maxLen, (i - j - 1));
            if(i == len)
                return maxLen;
        }
        return maxLen;
    }
};

/**
 * from discuss
 * 遇到重复字符时，从上一个重复字符的index+1开始搜索
 * 用hashtable存储每个字符上一次出现的位置
 * 用start记录子串开头的位置
 * 如果字符在上一次出现的位置小于start，说明该字符在本子串中并没有出现过，更新该字符的位置为当前index
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_map<char, int> hashTable;
        int len = s.length();
        int start = 0;
        for(int i = 0; i < len; i ++) {
            if(hashTable.find(s[i]) != hashTable.end() && hashTable[s[i]] >= start) {
                maxLen = max(maxLen, i - start);
                start = hashTable[s[i]] + 1;
                hashTable[s[i]] = i;
            }
            hashTable[s[i]] = i;
        }
        maxLen = max(maxLen, len - start);
        return maxLen;
    }
};
