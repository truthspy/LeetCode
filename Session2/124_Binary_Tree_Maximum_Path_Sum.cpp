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
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        int res = INT_MIN;
        getMaxPath(root, res);
        return res;
    }
    int getMaxPath(TreeNode* root, int& res) {
        if(root == NULL)
            return 0;
        int left = getMaxPath(root->left, res);
        int right = getMaxPath(root->right, res);
        int cur = root->val;
        if(left > 0)
            cur += left;
        if(right > 0)
            cur += right;
        res = max(res, cur);
        return max(root->val, root->val + max(left, right));
    }
};
