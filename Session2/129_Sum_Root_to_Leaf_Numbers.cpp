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
        int sum = 0;
        if(root == NULL)
            return 0;
        getSum(root, 0, sum);
        return sum;
    }
    void getSum(TreeNode* root, int cur, int& sum) {
        cur = cur * 10 + root->val;
        if(root->left == NULL && root->right == NULL) {
            sum += cur;
            return;
        }
        if(root->left)
            getSum(root->left, cur, sum);
        if(root->right)
            getSum(root->right, cur, sum);
    }
};
