/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
// 要求O(1)空间，用queue不合适 TODO
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
    }
};
/*
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> q;
        if(root != NULL)
            q.push(root);
        int count = 1;
        while(!q.empty()) {
            TreeLinkNode *pre = NULL;
            TreeLinkNode *cur = NULL;
            for(int i = 0; i < count; i ++) {
                cur = q.front();
                q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
                if(pre)
                    pre->next = cur;
                pre = cur;
            }
            count = q.size();
        }
    }
};
*/
