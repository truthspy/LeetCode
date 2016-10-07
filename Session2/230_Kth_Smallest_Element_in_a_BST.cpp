/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// follow-up:如果多次调用的话，可以改变treenode的数据结构，加一个变量保存节点左边有多少个节点，这样就可以用类似二分的方法来做
// http://www.geeksforgeeks.org/find-k-th-smallest-element-in-bst-order-statistics-in-bst/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur) {
            s.push(cur);
            cur = cur->left;
        }
        while(!s.empty()) {
            cur = s.top();
            s.pop();
            k --;
            if(k == 0)
                return cur->val;
            cur = cur->right;
            while(cur) {
                s.push(cur);
                cur = cur->left;
            }
        }
        return -1;
    }
};
