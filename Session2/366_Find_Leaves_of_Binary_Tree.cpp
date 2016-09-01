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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        getDepth(root, res);
        return res;
    }
    int getDepth(TreeNode* root, vector<vector<int>> &res) {
        if(root == NULL)
            return -1;
        int leftDepth = getDepth(root->left, res);
        int rightDepth = getDepth(root->right, res);
        int maxDepth = max(leftDepth, rightDepth) + 1;
        if(res.size() == maxDepth) {
            vector<int> newLevel;
            newLevel.push_back(root->val);
            res.push_back(newLevel);
        }
        else {
            res[maxDepth].push_back(root->val);
        }
        return maxDepth;
    }
};
