class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> letters(26, 0);
        for(auto i : s)
            letters[i - 'a'] ++;
        for(auto i : t) {
            letters[i - 'a'] --;
            if(letters[i - 'a'] < 0)
                return i;
        }
        char res;
        return res;
    }
};
