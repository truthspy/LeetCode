/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//new version
//a more clear one

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> treeStack;
        TreeNode* node = root;
        while(node != NULL || !treeStack.empty()) {
            while(node != NULL) {
                treeStack.push(node);
                node = node->left;
            }
            node = treeStack.top();
            treeStack.pop();
            inorder.push_back(node->val);
            node = node->right; //important: 不用判断是否为null，直接压入，while循环会判断
        }
        return inorder;
    }
};


 //old version
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> treeStack;
        TreeNode* node = root;
        if(root == NULL)
            return inorder;
        while(true) {
            while(node->left != NULL) {
                treeStack.push(node);
                node = node->left;
            }
            inorder.push_back(node->val);
            while(node->right == NULL && !treeStack.empty()) {
                node = treeStack.top();
                treeStack.pop();
                inorder.push_back(node->val);
            }
            if(node->right != NULL) {
                node = node->right;
            }
            else
                break;
        }
        return inorder;
    }
};
