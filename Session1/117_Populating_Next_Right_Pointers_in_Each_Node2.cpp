/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
/**
 * constant extra space所以不能用队列。。。
 * 然后去复习了一下这个题的简单版本。。。
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        while(root && (root->left || root->right)) {
            TreeLinkNode *nextLevel = root->left;
            if(!nextLevel)
                nextLevel = root->right;
            TreeLinkNode *cur = nextLevel;
            if(root->left && root->right) {
                cur->next = root->right;
                cur = cur->next;
            }
            while(root->next) {
                root = root->next;
                if(root->left) {
                    cur->next = root->left;
                    cur = cur->next;
                }
                if(root->right) {
                    cur->next = root->right;
                    cur = cur->next;
                }
            }
            while(nextLevel && !nextLevel->left && !nextLevel->right)
                nextLevel = nextLevel->next;
            root = nextLevel;
        }
    }
};
