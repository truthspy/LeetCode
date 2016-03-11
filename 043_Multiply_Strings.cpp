class Solution {
public:
    string multiply(string num1, string num2) {
        string result = "";
        if(num1.length() == 0 || num2.length() == 0)
            return result;
        if(num1 == "0" || num2 == "0")
            return "0";
        for(int i = num1.length() - 1; i >= 0; i --) {
            if(num1[i] == '0')
                continue;
            int carry = 0;
            string tmpResult = "";
            for(int j = num2.length() - 1; j >= 0; j --) {
                int curNum = ((num1[i] - '0') * (num2[j] - '0')) + carry;
                carry = curNum / 10;
                curNum = curNum % 10;
                tmpResult = to_string(curNum) + tmpResult;
            }
            if(carry != 0)
                tmpResult = to_string(carry) + tmpResult;
            string addResult = "";
            int m = result.length() - 1;
            int n = tmpResult.length() - 1;
            carry = 0;
            int shift = num1.length() - i - 1;
            while(m >= 0 && shift > 0) {
                addResult = result[m] + addResult;
                m --;
                shift --;
            }
            while(shift > 0) {
                addResult = '0' + addResult;
                shift --;
            }
            while(m >= 0 || n >= 0) {
                int total = carry;
                if(m >= 0) {
                    total += (result[m] - '0');
                    m --;
                }
                if(n >= 0) {
                    total += (tmpResult[n] - '0');
                    n --;
                }
                carry = total / 10;
                total = total % 10;
                addResult = to_string(total) + addResult;
            }
            if(carry != 0)
                addResult = to_string(carry) + addResult;
            result = addResult;
        }
        return result;
    }
};

//TODO
//比较快速的方法： `num1[i] * num2[j]` will be placed at indices `[i + j`, `i + j + 1]` 
//https://leetcode.com/discuss/71593/easiest-java-solution-with-graph-explanation
