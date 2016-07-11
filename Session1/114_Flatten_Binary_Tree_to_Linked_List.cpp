/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        TreeNode* dummy = new TreeNode(0);
        dummy->right = root;
        TreeNode* pre = dfs(root, dummy);
        pre->left = NULL;
        pre->right = NULL;
        root = dummy->right;
    }
    TreeNode* dfs(TreeNode* root, TreeNode* pre) {
        if(root == NULL)
            return pre;
        TreeNode* right = root->right;
        pre->right = root;
        pre->left = NULL;
        TreeNode* tmp = dfs(root->left, pre->right);
        return dfs(right, tmp);
    }
};
