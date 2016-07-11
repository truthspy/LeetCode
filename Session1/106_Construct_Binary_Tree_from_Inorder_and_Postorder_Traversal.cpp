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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeDFS(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
    TreeNode* buildTreeDFS(Iter iBegin, Iter iEnd, Iter pBegin, Iter pEnd) {
        if(pBegin == pEnd)
            return NULL;
        int rootVal = *(pEnd - 1);
        TreeNode *root = new TreeNode(rootVal);
        Iter rootPos = find(iBegin, iEnd, rootVal);
        root->left = buildTreeDFS(iBegin, rootPos, pBegin, pBegin + (rootPos - iBegin));
        root->right = buildTreeDFS(rootPos + 1, iEnd, pBegin + (rootPos - iBegin), pEnd - 1);
        return root;
    }
};
