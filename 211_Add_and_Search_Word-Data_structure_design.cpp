class MyNode {
public:
    MyNode *child[26];
    bool valid;
    MyNode() {
        for(int i = 0; i < 26; i ++)
            child[i] = NULL;
        valid = false;
    }
};

class WordDictionary {
private:
    MyNode *root;
public:

    WordDictionary() {
        root = new MyNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        int len = word.length();
        int i = 0;
        MyNode *curNode = root;
        while(i < len) {
            int pos = word[i] - 'a';
            if(!curNode->child[pos])
                curNode->child[pos] = new MyNode();
            curNode = curNode->child[pos];
            i ++;
        }
        curNode->valid = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        int len = word.length();
        int i = 0;
        if(len == 0)
            return root->valid;
        MyNode *curNode = root;
        return searchHelper(word, root, len, 0);
    }
    bool searchHelper(string word, MyNode *curNode, int len, int pos) {
        if(curNode == NULL)
            return false;
        if(pos == len) {
            return curNode->valid;
        }
        char cur = word[pos];
        if(cur != '.')
            return searchHelper(word, curNode->child[cur-'a'], len, pos + 1);
        for(int i = 0; i < 26; i ++)
            if(searchHelper(word, curNode->child[i], len, pos + 1))
                return true;
        return false;
    }
};



// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
