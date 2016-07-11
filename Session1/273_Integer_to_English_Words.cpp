/**
 * 抄答案呀抄答案
 */
class Solution {
public:
    
    string helper(int num) {
        vector<string> Lower_Than_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> Tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        if(num == 0)
            return "";
        else if(num < 20)
            return Lower_Than_20[num] + " ";
        else if(num < 100)
            return Tens[num / 10] + " " + helper(num % 10); //直接调用Lower_Than_20数组，可能会缺失后面的" "
        else
            return helper(num / 100) + "Hundred " + helper(num % 100);
    }
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        vector<string> Thousands = {"", "Thousand", "Million", "Billion"};
        int i = 0;
        string res = "";
        while(num != 0) {
            // res = Thousands[i] + res;   有可能出现10000000的情况，不能直接加
            if(num % 1000 != 0) {
                res = helper(num % 1000) + Thousands[i] + " " + res;
            }
            num = num / 1000;
            i ++;
        }
        int len = res.length();
        i = len - 1;
        while(res[i] == ' ') {
            res = res.erase(i);   //删除结尾的" "
            i --;
        }
        return res;
    }
};
