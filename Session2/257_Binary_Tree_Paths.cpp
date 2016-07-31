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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL)
            return res;
        string solution = "";
        getTreePaths(root, solution, res);
        return res;
    }
    void getTreePaths(TreeNode* root, string solution, vector<string>& res) {
        solution += to_string(root->val);
        if(!root->left && !root->right) {
            res.push_back(solution);
            return;
        }
        if(root->left) {
            getTreePaths(root->left, solution + "->", res);
        }
        if(root->right) {
            getTreePaths(root->right, solution + "->", res);
        }
    }
};
