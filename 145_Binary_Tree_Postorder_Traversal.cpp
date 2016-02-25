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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        stack<TreeNode*> treeStack;
        TreeNode* node = root;
        while(node != NULL || !treeStack.empty()) {
            while(node != NULL) {
                treeStack.push(node);
                node = node->left;
            }
            node = treeStack.top();
            if(node->right == NULL) {
                postorder.push_back(node->val);
                treeStack.pop();
                node = NULL;
            }
            else {
                TreeNode* tmp = node->right;
                node->right = NULL;
                node = tmp;
            }
        }
        return postorder;
    }
};
