/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
 注意：
 1. 注意判断叶节点
 2. 存在负数情况，不能剪枝
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        if(root->left != NULL || root->right != NULL) {
            sum = sum - root->val;
            return (hasPathSum(root->left, sum) || hasPathSum(root->right, sum));
        }
        sum = sum - root->val;
        if(sum == 0)
            return true;
        else
            return false;
    }
};
