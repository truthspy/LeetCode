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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root == NULL)
            return preorder;
        stack<TreeNode *> treeStack;
        treeStack.push(root);
        while(!treeStack.empty()) {
            TreeNode* cur = treeStack.top();
            treeStack.pop();
            preorder.push_back(cur->val);
            if(cur->right != NULL)
                treeStack.push(cur->right);
            if(cur->left != NULL)
                treeStack.push(cur->left);
        }
        return preorder;
    }
};
