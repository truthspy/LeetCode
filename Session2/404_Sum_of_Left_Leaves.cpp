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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        return (sumOfLeaves(root->left, true) + sumOfLeaves(root->right, false));
    }
    int sumOfLeaves(TreeNode* root, bool left) {
        if(root == NULL)
            return 0;
        if(!root->left && !root->right && left)
            return root->val;
        int res = 0;
        if(root->left)
            res += sumOfLeaves(root->left, true);
        if(root->right)
            res += sumOfLeaves(root->right, false);
        return res;
    }
};
