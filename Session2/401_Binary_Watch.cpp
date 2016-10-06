// bitset这个方法很好
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for(int h = 0; h <= 11; h ++) {
            for(int m = 0; m <= 59; m ++) {
                int cur = (h << 6) + m;
                if(bitset<10>(cur).count() == num) {
                    string curRes = to_string(h) + ":";
                    if(m <= 9)
                        curRes += "0";
                    curRes += to_string(m);
                    res.push_back(curRes);
                }
            }
        }
        return res;
    }
};
