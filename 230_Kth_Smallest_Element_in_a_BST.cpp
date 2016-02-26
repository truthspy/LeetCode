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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> inorder;
        TreeNode* node = root;
        while(node != NULL || !inorder.empty()) {
            while(node != NULL) {
                inorder.push(node);
                node = node->left;
            }
            node = inorder.top();
            inorder.pop();
            k --;
            if(k == 0)
                return node->val;
            node = node->right;
        }
        return -1;
    }
};

/*
follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

1.Try to utilize the property of a BST.
2.What if you could modify the BST node's structure?
在节点中记录它的左边有多少个节点
3.The optimal runtime complexity is O(height of BST).
*/
