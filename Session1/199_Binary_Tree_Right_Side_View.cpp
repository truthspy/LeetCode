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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> tree;
        vector<int> rightView;
        if(root == NULL)
            return rightView;
        tree.push(root);
        while(!tree.empty()) {
            int size = tree.size();
            for(int i = 0; i < size; i ++) {
                TreeNode* cur = tree.front();
                if(i == size -1)
                    rightView.push_back(cur->val);
                if(cur->left != NULL)
                    tree.push(cur->left);
                if(cur->right != NULL)
                    tree.push(cur->right);
                tree.pop();
            }
        }
        return rightView;
    }
};
