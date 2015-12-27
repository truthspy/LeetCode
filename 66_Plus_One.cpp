class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool add = true;
        int i = digits.size() - 1;
        while (i >= 0) {
            if(add)
                digits[i] ++;
            if(digits[i] == 10) {
                digits[i] = 0;
            }
            else {
                add = false;
                break;
            }
            i --;
        }
        if(i == -1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
