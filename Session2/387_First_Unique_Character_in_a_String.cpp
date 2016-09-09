class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> dict(26, 0);
        vector<int> index(26, -1);
        for(int i = 0; i < s.size(); i ++) {
            int pos = s[i] - 'a';
            dict[pos] ++;
            if(dict[pos] == 1)
                index[pos] = i;
        }
        int res = INT_MAX;
        for(int i = 0; i < 26; i ++) {
            if(dict[i] == 1)
                res = min(res, index[i]);
        }
        if(res == INT_MAX)
            return -1;
        return res;
    }
};
