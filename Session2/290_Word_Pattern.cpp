class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> toStr(26, "");
        unordered_map<string, int> toPattern;
        for(auto c : pattern) {
            if(str == "")
                return false;
            string cur;
            int pos = str.find(' ');
            if(pos == string::npos) {
                cur = str;
                pos = str.length() - 1;
            }
            else
                cur = str.substr(0, pos);
            str = str.substr(pos + 1);
            if(toStr[c - 'a'] == cur)
                continue;
            if(toStr[c - 'a'] == "" && toPattern.find(cur) == toPattern.end()) {
                toPattern[cur] = c - 'a';
                toStr[c - 'a'] = cur;
            }
            else 
                return false;
        }
        return str == "";
    }
};
