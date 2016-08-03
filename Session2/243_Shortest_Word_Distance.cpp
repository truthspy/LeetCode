class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int len = words.size();
        int last1 = -1;
        int last2 = -1;
        int minDistance = len;
        for(int i = 0; i < len; i ++) {
            if(words[i] == word1) {
                last1 = i;
                if(last2 != -1) {
                    minDistance = min(minDistance, i - last2);
                }
            }
            if(words[i] == word2) {
                last2 = i;
                if(last1 != -1) {
                    minDistance = min(minDistance, i - last1);
                }
            }
        }
        return minDistance;
    }
};
