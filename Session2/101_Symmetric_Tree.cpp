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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isSubSymmetric(root->left, root->right);
    }
    bool isSubSymmetric(TreeNode* left, TreeNode* right) {
        if(!left && !right)
            return true;
        if(!left || !right)
            return false;
        if(left->val != right->val)
            return false;
        return (isSubSymmetric(left->left, right->right) && isSubSymmetric(left->right, right->left));
    }
};
