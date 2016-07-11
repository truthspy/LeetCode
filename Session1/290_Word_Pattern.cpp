class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int len = pattern.length();
        vector<string> vecstr;
        istringstream myin(str);
        string word;
        while(myin >> word)
            vecstr.push_back(word);
        if(len != vecstr.size())
            return false;
        unordered_map<char,string> mpattern;
        unordered_map<string,char> mstr;
        for(int i = 0; i < len; i ++) {
            if(mpattern.find(pattern[i]) == mpattern.end() && mstr.find(vecstr[i]) == mstr.end()) {
                mpattern[pattern[i]] = vecstr[i];
                mstr[vecstr[i]] = pattern[i];
            }
            else if(mpattern[pattern[i]] == vecstr[i] && mstr[vecstr[i]] == pattern[i])
                continue;
            else
                return false;
        }
        return true;
    }
};
