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
    int sumNumbers(TreeNode* root) {
        int result = 0;
        if(root != NULL)
            countSum(root, result, 0);
        return result;
    }
    void countSum(TreeNode* node, int& result, int path) {
        path = path * 10 + node->val;
        if(node->left == NULL && node->right == NULL)
            result += path;
        if(node->left != NULL) {
            countSum(node->left, result, path);
        }
        if(node->right != NULL) {
            countSum(node->right, result, path);
        }
    }
};
