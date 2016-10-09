class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        while(i >= 0 && j >= 0) {
            int num = (num1[i] - '0') + (num2[j] - '0') + carry;
            carry = num / 10;
            num = num % 10;
            res += to_string(num);
            i --;
            j --;
        }
        while(i >= 0) {
            int num = (num1[i] - '0') + carry;
            carry = num / 10;
            num = num % 10;
            res += to_string(num);
            i --;
        }
        while(j >= 0) {
            int num = (num2[j] - '0') + carry;
            carry = num / 10;
            num = num % 10;
            res += to_string(num);
            j --;
        }
        if(carry != 0)
            res += "1";
        reverse(res.begin(), res.end());
        return res;
    }
};
