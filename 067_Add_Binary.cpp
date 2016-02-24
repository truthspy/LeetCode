/*
思路from discuss
可以通过计算进位以及两个数该位的和，得到sum，
sum/2是进位，sum%2是该位的值
但是运行速度会变慢
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length();
        int len2 = b.length();
        int i = len1 - 1;
        int j = len2 - 1;
        int carry = 0;
        string result = "";
        while(i >= 0 || j >= 0) {
            int sum = carry;
            if(i >= 0) {
                sum += (a[i] - '0');
                i --;
            }
            if(j >= 0) {
                sum += (b[j] - '0');
                j --;
            }
            result = to_string(sum % 2) + result;
            carry = sum / 2;
        }
        if(carry == 1)
            result = "1" + result;
        return result;
    }
};
//bad version
//但是运行速度快
/*
class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length();
        int len2 = b.length();
        int i = len1 - 1;
        int j = len2 - 1;
        bool add = 0;
        while(i >= 0 && j >= 0) {
            if(!add) {
                if(a[i] == '1' && b[j] == '1') {
                    add = 1;
                    a[i] = '0';
                }
                else if(a[i] == '0' && b[j] == '0')
                    add = 0;
                else
                    a[i] = '1';
            }
            else {
                if(a[i] == '1' && b[j] == '1')
                    add = 1;
                else if(a[i] == '0' && b[j] == '0') {
                    add = 0;
                    a[i] = '1';
                }
                else {
                    add = 1;
                    a[i] = '0';
                }
            }
            i --;
            j --;
        }
        if(i < 0 && j < 0 && add)
            a = '1' + a;
        else if(i >= 0 && j < 0 && add) {
            while(i >= 0) {
                if(add && a[i] == '1')
                    a[i] = '0';
                else if(add) {
                    a[i] = '1';
                    add = 0;
                }
                i --;
            }
            if(add)
                a = '1' + a;
        }
        else if(j >= 0 && i < 0) {
            while(j >= 0) {
                if(add && b[j] == '1')
                    a = '0' + a;
                else if(add){
                    a = '1' + a;
                    add = 0;
                }
                else
                    a = b[j] + a;
                j --;
            }
            if(add)
                a = '1' + a;
        }
        return a;
    }
};
*/
