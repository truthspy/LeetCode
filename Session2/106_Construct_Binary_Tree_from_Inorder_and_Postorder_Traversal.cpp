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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(0, n - 1, 0, n - 1, inorder, postorder);
    }
    TreeNode* build(int pl, int pr, int il, int ir, vector<int>& inorder, vector<int>& postorder) {
        if(pl > pr)
            return NULL;
        if(pl == pr)
            return new TreeNode(postorder[pl]);
        int rootVal = postorder[pr];
        int rootPos = 0;
        for(int i = il; i <= ir; i ++) {
            if(rootVal == inorder[i]) {
                rootPos = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(pl, pl + rootPos - il - 1, il, rootPos - 1, inorder, postorder);
        root->right = build(pl + rootPos - il, pr - 1, rootPos + 1, ir, inorder, postorder);
        return root;
    }
};
