class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string digitToLetter[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int len = digits.size();
        vector<string> result;
        if(len == 0)
            return result;
        string solution = "";
        getLetters(digits, result, 0, solution, digitToLetter);
        return result;
    }
    void getLetters(string digits, vector<string>& result, int start, string solution, string* digitToLetter) {
        if(start == digits.length()) {
            result.push_back(solution);
            return;
        }
        int i = 0;
        string curDigit = digitToLetter[digits[start] - '0'];
        while(i < curDigit.length()) {
            getLetters(digits, result, start + 1, solution + curDigit[i], digitToLetter);
            i ++;
        }
    }
};

//非递归算法可以用队列实现
