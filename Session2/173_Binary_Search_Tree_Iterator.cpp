/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> treeStack;
public:
    BSTIterator(TreeNode *root) {
        while(root) {
            treeStack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !treeStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* cur = treeStack.top();
        treeStack.pop();
        int val = cur->val;
        cur = cur->right;
        while(cur) {
            treeStack.push(cur);
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
