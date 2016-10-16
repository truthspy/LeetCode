class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int size = s.size();
        int start = 0;
        for(int i = 0; i <= size; i ++) {
            if(i == size || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
    }
};
