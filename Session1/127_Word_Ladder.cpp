/**
 * http://www.cnblogs.com/grandyang/p/4539768.html
 * 看完答案写的
 * 也可以用类似BFS的方法，不用map，每次把queue里上次加入的弹空，然后记录循环进行了多少次就可以。
 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        queue<string> findWords;
        unordered_map<string, int> mp;
        mp[beginWord] = 1;
        findWords.push(beginWord);
        while(!findWords.empty()) {
            string oldWord = findWords.front();
            findWords.pop();
            int len = mp[oldWord];
            for(int j = 0; j < oldWord.size(); j ++) {
                string word = oldWord;
                for(int i = 0; i < 26; i ++) {
                    word[j] = i + 'a';
                    if(word == endWord)
                        return len + 1;
                    if(wordList.find(word) != wordList.end() && mp.find(word) == mp.end()) {
                        findWords.push(word);
                        mp[word] = len + 1;
                    }
                }
            }
        }
        return 0;
    }
};
