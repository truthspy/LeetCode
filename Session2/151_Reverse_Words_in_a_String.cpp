class Solution {
public:
    void reverseWords(string &s) {
        int n = s.size();
        int pos = 0;
        int count = 1;
        for(int i = 0; i < n; i ++) {
            if(s[i] != ' ')
                count = 0;
            else if(s[i] == ' ') {
                if(count != 0)
                    continue;
                count = 1;
            }
            s[pos] = s[i];
            pos ++;
        }
        pos --;
        while(s[pos] == ' ') {
            s.pop_back();
            pos --;
        }
        s.resize(pos + 1);
        reverse(s.begin(), s.end());
        int start = 0;
        int newSize = s.size();
        for(int i = 0; i <= newSize; i ++) {
            if(i == newSize || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
    }
};
