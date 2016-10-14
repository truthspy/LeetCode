class Solution {
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    class TrieNode {
    public:
        bool isValid;
        TrieNode* child[26];
        TrieNode() {
            for(int i = 0; i < 26; i ++)
                child[i] = NULL;
            isValid = false;
        }
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int n = board.size();
        if(n == 0)
            return res;
        int m = board[0].size();
        int size = words.size();
        TrieNode* root = new TrieNode();
        TrieNode* curNode = root;
        for(int i = 0; i < size; i ++) {
            int j = 0;
            curNode = root; // 每次要重新指回根节点！！
            while(j < words[i].size()) {
                int cur = words[i][j] - 'a';
                if(curNode->child[cur] == NULL)
                    curNode->child[cur] = new TrieNode();
                curNode = curNode->child[cur];
                j ++;
            }
            curNode->isValid = true;
        }
        if(root->isValid)
            res.push_back("");
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++)
                dfs(root, i, j, board, res, "");
        }
        return res;
    }
    void dfs(TrieNode* root, int x, int y, vector<vector<char>>& board, vector<string>& res, string curRes) {
        int n = board.size();
        int m = board[0].size();
        if(x < 0 || y < 0 || x >= n || y >= m)
            return;
        if(board[x][y] == '0')
            return;
        int cur = board[x][y] - 'a';
        if(root->child[cur] != NULL) {
            curRes += board[x][y];
            if(root->child[cur]->isValid) {
                res.push_back(curRes);
                root->child[cur]->isValid = false; // 注意！！找到之后要变成非valid，防止重复！！
            }
            board[x][y] = '0';
            for(int i = 0; i < 4; i ++)
                dfs(root->child[cur], x + dir[i][0], y + dir[i][1], board, res, curRes);
            board[x][y] = cur + 'a';
        }
    }
};
