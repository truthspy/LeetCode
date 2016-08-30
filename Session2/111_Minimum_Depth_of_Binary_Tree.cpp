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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        int minDep = INT_MAX;
        // 要注意只有一个子节点，不是leaf
        if(root->left)
            minDep = minDepth(root->left) + 1;
        if(root->right)
            minDep = min(minDepth(root->right) + 1, minDep);
        return minDep;
    }
};
