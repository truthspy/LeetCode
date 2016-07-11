class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isTwoNodeSame(root->left, root->right);
    }
    bool isTwoNodeSame(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL)
            return true;
        if(root1 == NULL || root2 == NULL)
            return false;
        if(root1->val != root2->val)
            return false;
        return (isTwoNodeSame(root1->left, root2->right) && isTwoNodeSame(root1->right, root2->left));
    }
};
