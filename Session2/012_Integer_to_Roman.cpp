// Ⅰ（1）、X（10）、C（100）、M（1000）、V（5）、L（50）、D（500）
class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        int nums[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string romans[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        for(int i = 12; i >= 0; i --) {
            int cnt = num / nums[i];
            num = num % nums[i];
            while(cnt > 0) {
                cnt --;
                res += romans[i];
            }
            if(num == 0)
                break;
        }
        return res;
    }
};
