class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* child[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for(int i = 0; i < 26; i ++)
            child[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.length(); i ++) {
            int pos = word[i] - 'a';
            if(cur->child[pos] == NULL)
                cur->child[pos] = new TrieNode();
            cur = cur->child[pos];
        }
        cur->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* cur = root;
        if(root == NULL)
            return false;
        for(int i = 0; i < word.length(); i ++) {
            int pos = word[i] - 'a';
            cur = cur->child[pos];
            if(cur == NULL)
                return false;
        }
        return cur->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        if(root == NULL)
            return false;
        for(int i = 0; i < prefix.length(); i ++) {
            int pos = prefix[i] - 'a';
            cur = cur->child[pos];
            if(cur == NULL)
                return false;
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
