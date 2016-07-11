/**
 * 看完http://www.cnblogs.com/grandyang/p/5294255.html抄的
 * 还只抄了一种方法，第一种没抄
 */
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        result.push_back(0);
        for(int i = 1; i <= num; i ++) {
            if(i % 2 == 0)
                result.push_back(result[i / 2]);
            else
                result.push_back(result[i / 2] + 1);
        }
        return result;
    }
};
