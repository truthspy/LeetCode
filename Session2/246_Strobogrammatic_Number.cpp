class Solution {
public:
    bool isStrobogrammatic(string num) {
        string newNum = "";
        int len = num.length();
        for(int i = 0; i < len; i ++) {
            if(num[i] == '0' || num[i] == '1' || num[i] == '8')
                newNum = num[i] + newNum;
            else if(num[i] == '6')
                newNum = '9' + newNum;
            else if(num[i] == '9')
                newNum = '6' + newNum;
            else
                return false;
        }
        return num == newNum;
    }
};
