/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //其实就是中序遍历，但是想不到要这么做才能满足空间复杂度啊
 
class BSTIterator {
    stack<TreeNode*> inorder;
public:
    BSTIterator(TreeNode *root) {
        while(root != NULL) {
            inorder.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!inorder.empty());
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* cur = inorder.top();
        int val = cur->val;
        inorder.pop();
        cur = cur->right;
        while(cur != NULL) {
            inorder.push(cur);
            cur = cur->left;
        }
        return val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
