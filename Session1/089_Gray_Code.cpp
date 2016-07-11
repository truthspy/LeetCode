//有更简单更快的方法
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        if(n < 0)
            return result;
        result.push_back(0);
        int x = 0;
        while(true) {
            int i = 0;
            for(i = 0; i < n; i ++) {
                int posBit = (x >> i) & 1;
                posBit = 1 - posBit;
                int mask = ~(1 << i);
                int val = (x & mask) | (posBit << i);
                if(find(result.begin(), result.end(), val) == result.end()) {
                    result.push_back(val);
                    x = val;
                    break;
                }
            }
            if(i == n)
                break;
        }
        return result;
    }
};
