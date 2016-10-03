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
    int longestConsecutive(TreeNode* root) {
        if(root == NULL)
            return 0;
        int maxRes = 1;
        getLongest(root->left, root->val, 1, maxRes);
        getLongest(root->right, root->val, 1, maxRes);
        return maxRes;
    }
    void getLongest(TreeNode* root, int parentVal, int curLen, int &maxRes) {
        if(root == NULL)
            return;
        if(root->val != (parentVal + 1))
            curLen = 0;
        curLen ++;
        maxRes = max(maxRes, curLen);
        getLongest(root->left, root->val, curLen, maxRes);
        getLongest(root->right, root->val, curLen, maxRes);
    }
};
