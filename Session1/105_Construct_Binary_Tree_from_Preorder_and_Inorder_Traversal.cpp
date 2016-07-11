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
    typedef vector<int>::iterator Iter;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeDFS(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    TreeNode* buildTreeDFS(Iter pBegin, Iter pEnd, Iter iBegin, Iter iEnd) {
        if(pBegin == pEnd)
            return NULL;
        TreeNode *root = new TreeNode(*pBegin);
        Iter rootInorder = find(iBegin, iEnd, root->val);
        root->left = buildTreeDFS(pBegin + 1, pBegin + 1 + (rootInorder - iBegin), iBegin, rootInorder);
        root->right = buildTreeDFS(pBegin + 1 + (rootInorder - iBegin), pEnd, rootInorder + 1, iEnd);
        return root;
    }
};
