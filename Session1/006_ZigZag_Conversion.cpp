//Version 1
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)//1的情况要单独考虑
            return s;
        string result = "";
        vector<string> zigzag(numRows);
        int size = s.length();
        int step = 1;
        int row = 0;
        for(int i = 0; i < size; i ++) {
            zigzag[row].push_back(s[i]);
            if(row == 0)
                step = 1;
            if(row == numRows - 1)
                step = -1;
            row += step;
        }
        for(int i = 0; i < numRows; i ++)
            result += zigzag[i];
        return result;
    }
};

//Version 2
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)//1的情况要单独考虑
            return s;
        string result = "";
        int len = s.length();
        int total = (numRows - 1) * 2;
        for(int i = 0; i < numRows; i ++) {
            int j = i;
            int gap = 2 * i;
            while(j < len) {
                result += s[j];
                gap = total - gap;
                if(gap == 0)
                    gap = total - gap;
                j += gap;
            }
        }
        return result;
    }
};
