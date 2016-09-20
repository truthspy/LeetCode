// can use only one unordered_map
// minus 1 each time
class Solution {
public:
    string minWindow(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();
        unordered_map<char, int> mp;
        for(int i =0; i < tLen; i ++)
            mp[t[i]] ++;
        int l = 0;
        int count = 0;
        int minLen = sLen + 1;
        string res = "";
        for(int r = 0; r < sLen; r ++) {
            if(mp.find(s[r]) != mp.end()) {
                mp[s[r]] --;
                if(mp[s[r]] >= 0)
                    count ++;
            }
            while(count == tLen) {
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    res = s.substr(l, minLen);
                }
                if(mp.find(s[l]) != mp.end()) {
                    mp[s[l]] ++;
                    if(mp[s[l]] > 0)
                        count --;
                }
                l ++;
            }
        }
        return res;
    }
};
/*
class Solution {
public:
    string minWindow(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();
        unordered_map<char, int> tMap;
        int count = 0;
        for(int i = 0; i < tLen; i ++) {
            if(tMap.find(t[i]) == tMap.end())
                count ++;
            tMap[t[i]] ++;
        }
        unordered_map<char, int> mp;
        int curCount = 0;
        int minLen = sLen + 1;
        string res = "";
        int l = 0;
        for(int r = 0; r < sLen; r ++) {
            if(tMap.find(s[r]) != tMap.end()) {
                mp[s[r]] ++;
                if(mp[s[r]] == tMap[s[r]])
                    curCount ++;
            }
            while(count == curCount) {
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    res = s.substr(l, r - l + 1);
                }
                if(tMap.find(s[l]) != tMap.end()) {
                    mp[s[l]] --;
                    if(mp[s[l]] < tMap[s[l]])
                        curCount --;
                }
                l ++;
            }
        }
        return res;
    }
};
*/
