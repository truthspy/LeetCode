class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* next[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for(int i = 0; i < 26; i ++)
            next[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur = root;
        int len = word.length();
        for(int i = 0; i < len; i ++) {
            int pos = word[i] - 'a';
            if(cur->next[pos] == NULL)
                cur->next[pos] = new TrieNode();
            cur = cur->next[pos];
        }
        cur->isWord = true;
        
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* cur = root;
        int len = word.length();
        for(int i = 0; i < len; i ++) {
            int pos = word[i] - 'a';
            if(cur->next[pos] == NULL)
                return false;
            cur = cur->next[pos];
        }
        return cur->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        int len = prefix.length();
        for(int i = 0; i < len; i ++) {
            int pos = prefix[i] - 'a';
            if(cur->next[pos] == NULL)
                return false;
            cur = cur->next[pos];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
