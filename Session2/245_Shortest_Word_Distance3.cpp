// shorter code
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int idx = -1;
        int minDiff = INT_MAX;
        int size = words.size();
        for(int i = 0; i < size; i ++) {
            if(words[i] == word1 || words[i] == word2) {
                if(idx != -1 && (word1 == word2 || words[idx] != words[i]))
                    minDiff = min(minDiff, i - idx);
                idx = i;
            }
        }
        return minDiff;
    }
};
/*
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int size = words.size();
        int minDiff = INT_MAX;
        if(word1 == word2) {
            int last = -1;
            for(int i = 0; i < size; i ++) {
                if(words[i] == word1) {
                    if(last != -1)
                        minDiff = min(minDiff, i - last);
                    last = i;
                }
            }
        }
        else {
            int last1 = -1;
            int last2 = -1;
            for(int i = 0; i < size; i ++) {
                if(words[i] == word1) {
                    if(last2 != -1)
                        minDiff = min(minDiff, i - last2);
                    last1 = i;
                }
                if(words[i] == word2) {
                    if(last1 != -1)
                        minDiff = min(minDiff, i - last1);
                    last2 = i;
                }
            }
        }
        return minDiff;
    }
};
*/
