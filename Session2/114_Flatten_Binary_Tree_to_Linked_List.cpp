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
    void flatten(TreeNode* root) {
        TreeNode* pre = NULL;
        TreeNode* cur = root;
        stack<TreeNode*> preorder;
        while(cur || !preorder.empty()) {
            while(cur) {
                if(pre) {
                    pre->right = cur;
                    pre->left = NULL;
                }
                if(cur->right)
                    preorder.push(cur->right);
                pre = cur;
                cur = cur->left;
            }
            if(!preorder.empty()) {
                cur = preorder.top();
                preorder.pop();
            }
        }
    }
};
