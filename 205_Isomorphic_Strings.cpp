/*
1. 注意情况："ab" "aa"
    -->双向map
2. 可以用char map[256]数组替代unordered_map
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        if(len1 != len2)
            return false;
         unordered_map<char,char> mapS;
         unordered_map<char,char> mapT;
         for(int i = 0; i < len1; i ++) {
            if(mapS.find(s[i]) == mapS.end() && mapT.find(t[i]) == mapT.end()) {
                mapS[s[i]] = t[i];
                mapT[t[i]] = s[i];
            }
            else {
                if(mapS[s[i]] == t[i] && mapT[t[i]] == s[i])
                    continue;
                else
                    return false;
            }
         }
         return true;
    }
};
