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
    map<TreeNode*, int> maxFalse;
    map<TreeNode*, int> maxTrue;
    int rob(TreeNode* root) {
        return max(DFS(root, true), DFS(root, false));
    }
    int DFS(TreeNode* root, bool choose) {
        if(root == NULL)
            return 0;
        if(maxFalse.find(root->left) == maxFalse.end())
            maxFalse[root->left] = DFS(root->left, false);
        if(maxFalse.find(root->right) == maxFalse.end())
            maxFalse[root->right] = DFS(root->right, false);
        if(choose)
            return root->val + maxFalse[root->left] + maxFalse[root->right];
        else {
            if(maxTrue.find(root->left) == maxTrue.end())
                maxTrue[root->left] = DFS(root->left, true);
            if(maxTrue.find(root->right) == maxTrue.end())
                maxTrue[root->right] = DFS(root->right, true);
            int l = max(maxFalse[root->left], maxTrue[root->left]);
            int r = max(maxFalse[root->right], maxTrue[root->right]);
            return l + r;
        }
    }
};
