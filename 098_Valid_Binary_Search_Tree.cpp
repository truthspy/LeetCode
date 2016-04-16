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
    bool isValidBST(TreeNode* root) {
        return isValidDFS(root, LONG_MIN, LONG_MAX);
    }
    bool isValidDFS(TreeNode* root, long lower, long upper) {
        if(root == NULL)
            return true;
        if(root->val <= lower || root->val >= upper)
            return false;
        return (isValidDFS(root->left, lower, root->val) && isValidDFS(root->right, root->val, upper));
    }
};
