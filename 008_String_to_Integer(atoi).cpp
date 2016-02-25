class Solution {
public:
    int myAtoi(string str) {
        long long result = 0;
        int len = str.length();
        if(len == 0)
            return 0;
        bool neg = false;
        int i = 0;
        while(i < len && str[i] == ' ') {
            i ++;
        }
        if(i < len && str[i] == '-') {
            neg = true;
            i ++;
        }
        else if(i < len && str[i] == '+') //1. "+1的情况" 2.用else if: "-+1"的情况
            i ++;
        if(i >= len)
            return 0;
        for( ; i < len; i ++) {
            if(str[i] >= '0' && str[i] <= '9') {
                if(neg)
                    result = result * 10 - (str[i] - '0');
                else
                    result = result * 10 + str[i] - '0';
            }
            else
                break;
            if(result > INT_MAX)
                return INT_MAX;
            if(result < INT_MIN)
                return INT_MIN;
        }
        return result;
    }
};
