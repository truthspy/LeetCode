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
        int min = 99999999;
        dfs(root, 1, min);
        return min;
    }
    void dfs(TreeNode* root, int depth, int& min) {
        if(root->left == NULL && root->right == NULL) {
            if(depth < min)
                min = depth;
        }
        if(depth >= (min - 1))
            return;
        if(root->left != NULL)
            dfs(root->left, depth + 1, min);
        if(root->right != NULL)
            dfs(root->right, depth + 1, min);
    }
};
