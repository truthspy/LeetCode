class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int size = strs.size();
        if(size == 0) //要判断为空的情况！并且要在下一语句之前！！
            return prefix;
        int len = strs[0].length();
        for(int i = 0; i < len; i ++) {
            char tmp = strs[0][i];
            for(int j = 1; j < size; j ++) {
                if(i >= strs[j].length())
                    return prefix;
                if(strs[j][i] != tmp)
                    return prefix;
            }
            prefix += tmp;
        }
        return prefix;
    }
};
