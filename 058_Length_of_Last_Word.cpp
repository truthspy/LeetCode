//找最后一个单词，从后往前更快
class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.length();
        int i = size - 1;
        while(i >= 0 && s[i] == ' ')
            i --;
        int count = 0;
        while(i >= 0 && s[i] != ' ') {
            count ++;
            i --;
        }
        return count;
    }
};
/*
old version
*/
/*
class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.length();
        int count = 0;
        int last = 0;
        for(int i = 0; i < size; i ++) {
            if(s[i] == ' ') {
                if(count != 0)
                    last = count;
                count = 0;
            }
            else
                count ++;
        }
        if(count == 0)
            return last;
        return count;
    }
};
*/
