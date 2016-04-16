/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * 思路：
 * 判断以当前节点为根的子树
 * 如果最左路径高度和最右路径高度相等，那么节点数为2^h-1
 * 否则左子树节点数目+右子树节点数目+1
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        int leftH = 1;
        int rightH = 1;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        while(left != NULL) {
            leftH ++;
            left = left->left;
        }
        while(right != NULL) {
            rightH ++;
            right = right->right;
        }
        if(leftH == rightH)
            return (pow(2, leftH) - 1);
        else
            return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
