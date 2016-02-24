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
