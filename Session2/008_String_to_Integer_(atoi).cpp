class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int i = 0;
        while(i < str.size() && str[i] == ' ')
            i ++;
        if(i == str.size())
            return 0;
        bool neg = false;
        if(str[i] == '+')
            i ++;
        else if(str[i] == '-') {
            neg = true;
            i ++;
        }
        while(i < str.size() && str[i] >= '0' && str[i] <= '9') {
            int tmp = res;
            if(neg) {
                res = res * 10 - (str[i] - '0');
                if(res / 10 != tmp) {
                    res = INT_MIN;
                    break;
                }
            }
            else {
                res = res * 10 + (str[i] - '0');
                if(res / 10 != tmp) {
                    res = INT_MAX;
                    break;
                }
            }
            i ++;
        }
        return res;
    }
};
