/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        TreeLinkNode* preLevel = root;
        TreeLinkNode* nextLevel;
        while(preLevel) {
            TreeLinkNode* cur = NULL;
            while(preLevel) {
                if(preLevel->left) {
                    cur = preLevel->left;
                    break;
                }
                if(preLevel->right) {
                    cur = preLevel->right;
                    break;
                }
                preLevel = preLevel->next;
            }
            if(cur == NULL)
                break;
            nextLevel = cur;
            if(preLevel->left) {
                if(preLevel->right) {
                    cur->next = preLevel->right;
                    cur = cur->next;
                }
            }
            preLevel = preLevel->next;
            while(preLevel) {
                if(preLevel->left) {
                    cur->next = preLevel->left;
                    cur = cur->next;
                }
                if(preLevel->right) {
                    cur->next = preLevel->right;
                    cur = cur->next;
                }
                preLevel = preLevel->next;
            }
            preLevel = nextLevel;
        }
    }
};
