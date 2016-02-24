class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        while(n != 0) {
            n = n - 1;
            char c = 'A' + n % 26;
            result = c + result;
            n = n / 26;
        }
        return result;
    }
};
