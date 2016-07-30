class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        vector<int> res(size + 1, 0);
        int i = size - 1;
        int add = 1;
        while(i >= 0) {
            int cur = digits[i] + add;
            res[i + 1] = cur % 10;
            add = cur / 10;
            i --;
        }
        res[0] = add;
        if(res[0] == 0)
            res.erase(res.begin());
        return res;
    }
};
