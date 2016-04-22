class TrieNode {
public:
    string s;
    TrieNode* child[26];
    TrieNode() {
        s = "";
        for(int i = 0; i < 26; i ++)
            child[i] = NULL;
    }
};
class TrieTree {
public:
    TrieNode *root;
    TrieTree() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode *cur = root;
        for(int i = 0; i < word.length(); i ++) {
            int tmp = word[i] - 'a';
            if(cur->child[tmp] == NULL)
                cur->child[tmp] = new TrieNode();
            cur = cur->child[tmp];
        }
        cur->s = word;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        if(words.empty() || board.empty() || board[0].empty())
            return result;
        TrieTree tree;
        int size = words.size();
        for(int i = 0; i < size; i ++) {
            tree.insert(words[i]);
        }
        int n = board.size();
        int m = board[0].size();
        TrieNode* curNode = tree.root;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                if(curNode->child[board[i][j] - 'a'] != NULL)
                    searchWords(result, board, i, j, curNode);
            }
        }
        return result;
    }
    void searchWords(vector<string>& result, vector<vector<char>>& board, int i, int j, TrieNode* cur) {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return;
        if(board[i][j] == '0')
            return;
        if(cur->child[board[i][j] - 'a'] == NULL)
            return;
        cur = cur->child[board[i][j] - 'a'];
        if(cur->s != "") {
            result.push_back(cur->s);
            cur->s = "";
        }
        char tmp = board[i][j];
        board[i][j] = '0';
        searchWords(result, board, i + 1, j, cur);
        searchWords(result, board, i - 1, j, cur);
        searchWords(result, board, i, j + 1, cur);
        searchWords(result, board, i, j - 1, cur);
        board[i][j] = tmp;
    }
};
