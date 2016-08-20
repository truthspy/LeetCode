class WordDistance {
private:
    unordered_map<string, vector<int>> mp;
public:
    WordDistance(vector<string>& words) {
        for(int i = 0; i < words.size(); i ++) {
            mp[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector<int> pos1 = mp[word1];
        vector<int> pos2 = mp[word2];
        int i = 0, j = 0;
        int minDiff = INT_MAX;
        while(i < pos1.size() && j < pos2.size()) {
            if(pos1[i] > pos2[j]) {
                minDiff = min(minDiff, pos1[i] - pos2[j]);
                j ++;
            }
            else {
                minDiff = min(minDiff, pos2[j] - pos1[i]);
                i ++;
            }
        }
        return minDiff;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
