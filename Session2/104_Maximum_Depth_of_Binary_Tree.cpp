/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 也可以不判断是不是叶子节点，直接返回1+max(maxDepth(root->left), maxDepth(root->right))
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(!root->left && !root->right)
            return 1;
        if(root->left && root->right)
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        if(root->left)
            return 1 + maxDepth(root->left);
        return 1 + maxDepth(root->right);
    }
};
