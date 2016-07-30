// az 和 ba属于同一组
// 所以不能用差值判断，要统一调整到某位的字母一样，判断其他位是否一样
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, int> mp;
        int resSize = 0;
        int size = strings.size();
        for(int i = 0; i < size; i ++) {
            string cur = strings[i];
            string curDiff = "";
            int len = strings[i].length();
            int diff = 'z' - strings[i][len - 1];
            for(int j = 0; j < len; j ++) {
                int c = strings[i][j] + diff;  //会越界
                if(c > (int)'z')
                    c = c - 26;
                curDiff += (char)c;
            }
            if(mp.find(curDiff) == mp.end()) {
                vector<string> tmp;
                tmp.push_back(strings[i]);
                res.push_back(tmp);
                mp[curDiff] = resSize;
                resSize ++;
            }
            else {
                res[mp[curDiff]].push_back(strings[i]);
            }
        }
        return res;
    }
};
