/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// TODO：再仔细想清楚逻辑
// 利用BST的性质，如果p比root小，则把res设为root，然后在root的左子树继续找，否则在右子树找
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res = NULL;
        while(root) {
            if(p->val < root->val) {
                res = root;
                root = root->left;
            }
            else
                root = root->right;
        }
        return res;
    }
};
/* 这个方法没有用到BST的性质
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> s;
        TreeNode* pre = NULL;
        TreeNode* cur = root;
        while(cur || !s.empty()) {
            while(cur) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            if(pre == p)
                return cur;
            pre = cur;
            cur = cur->right;
        }
        return NULL;
    }
};*/
