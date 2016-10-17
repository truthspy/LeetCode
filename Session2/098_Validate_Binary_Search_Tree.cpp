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
        return validBST(root, LONG_MIN, LONG_MAX);
    }
    bool validBST(TreeNode* root, long long curMin, long long curMax) {
        if(root == NULL)
            return true;
        if(root->val >= curMax || root->val <= curMin)
            return false;
        return validBST(root->left, curMin, root->val) && validBST(root->right, root->val, curMax);
    }
};
