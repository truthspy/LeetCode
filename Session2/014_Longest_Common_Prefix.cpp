class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.size() == 0)
            return res;
        int pos = 0;
        while(true) {
            if(pos >= strs[0].size())
                return res;
            char cur = strs[0][pos];
            for(int i = 1; i < strs.size(); i ++) {
                if(pos >= strs[i].size()) {
                    return res;
                }
                else if(strs[i][pos] != cur) {
                    return res;
                }
            }
            res += cur;
            pos ++;
        }
        return res;
    }
};
