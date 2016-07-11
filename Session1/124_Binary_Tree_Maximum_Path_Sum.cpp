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
        int maxVal = INT_MIN;
        getPath(root, maxVal);
        return maxVal;
    }
    int getPath(TreeNode* root, int& maxVal) {
        if(root == NULL)
            return 0;
        int left = getPath(root->left, maxVal);
        int right = getPath(root->right, maxVal);
        int curVal = root->val;
        if(left > 0)
            curVal += left;
        if(right > 0)
            curVal += right;
        maxVal = max(maxVal, curVal);
        return max(max(left + root->val, right + root->val), root->val);
    }
};
