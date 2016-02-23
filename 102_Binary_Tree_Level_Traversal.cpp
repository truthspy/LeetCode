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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if(root == NULL)
            return results;
        traversal(root, 0, results);
        return results;
    }
    void traversal(TreeNode* root, int depth, vector<vector<int>>& results) {
        if(depth >= results.size()) {
            vector<int> newLevel;
            newLevel.push_back(root->val);
            results.push_back(newLevel);
        }
        else {
            results[depth].push_back(root->val);
        }
        if(root->left != NULL)
            traversal(root->left, depth + 1, results);
        if(root->right != NULL)
            traversal(root->right, depth + 1, results);
    }
};
