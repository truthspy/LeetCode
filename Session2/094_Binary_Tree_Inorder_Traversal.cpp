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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> inorder;
        TreeNode* cur = root;
        while(!inorder.empty() || cur) {
            while(cur) {
                inorder.push(cur);
                cur = cur->left;
            }
            cur = inorder.top();
            res.push_back(cur->val);
            inorder.pop();
            cur = cur->right;
        }
        return res;
    }
};
