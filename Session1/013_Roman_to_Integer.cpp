class Solution {
public:
    int romanToInt(string s) {
        //建立对应关系，也可以用map
        int romanNum[26];
        romanNum['I' - 'A'] = 1;
        romanNum['V' - 'A'] = 5;
        romanNum['X' - 'A'] = 10;
        romanNum['C' - 'A'] = 100;
        romanNum['M' - 'A'] = 1000;
        romanNum['L' - 'A'] = 50;
        romanNum['D' - 'A'] = 500;
        int len = s.length();
        int intVal = 0;
        for(int i = len - 1; i >= 0; i --) {
            if(i == len - 1)
                intVal += romanNum[s[i] - 'A'];
            else {
                if(romanNum[s[i] - 'A'] < romanNum[s[i + 1] - 'A'])
                    intVal -= romanNum[s[i] - 'A'];
                else
                    intVal += romanNum[s[i] - 'A'];
            }
        }
        return intVal;
    }
};
/*
string s取某一个位置i的值：
1. s[i]
2. s.at(i)
*/
