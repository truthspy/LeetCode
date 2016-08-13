class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.length();
        vector<bool> wbreak(len + 1, false);
        wbreak[0] = true;
        for(int i = 1; i <= len; i ++) {
            for(int j = i - 1; j >= 0; j --) {
                string cur = s.substr(j, i - j);
                if(wbreak[j] && wordDict.find(cur) != wordDict.end()) {
                    wbreak[i] = true;
                    break;
                }
            }
        }
        return wbreak[len];
    }
};
