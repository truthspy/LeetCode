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
 思路：
 计算子树深度，并且比较左右子树深度，如果不平衡，返回-1.
 （-1这个记录方法好呀呀呀呀）
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int leftDepth = depth(root->left);
        if(leftDepth == -1)
            return false;
        int rightDepth = depth(root->right);
        if(rightDepth == -1)
            return false;
        if(abs(leftDepth - rightDepth) > 1)
            return false;
        return true;
    }
    int depth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int leftDepth = depth(root->left);
        if(leftDepth == -1)
            return -1;
        int rightDepth = depth(root->right);
        if(rightDepth == -1)
            return -1;
        if(abs(leftDepth - rightDepth) > 1)
            return -1;
        else
            return max(leftDepth, rightDepth) + 1; //记着+1！！！！
    }
};
