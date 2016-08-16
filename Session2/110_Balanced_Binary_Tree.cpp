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
    bool isBalanced(TreeNode* root) {
        if(getHeight(root) == -1)
            return false;
        return true;
    }
    int getHeight(TreeNode* root) {
        if(root == NULL)
            return 0;
        int leftH = getHeight(root->left);
        if(leftH == -1)
            return -1;
        int rightH = getHeight(root->right);
        if(rightH == -1)
            return -1;
        int diff = abs(leftH - rightH);
        if(diff > 1)
            return -1;
        return max(leftH, rightH) + 1;
    }
};
