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
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        int curMin, curMax;
        isBST(root, curMin, curMax, res);
        return res;
    }
    bool isBST(TreeNode* root, int& curMin, int& curMax, int& curRes) {
        if(root == NULL)
            return true;
        int leftRes = 0, rightRes = 0;
        int leftMin, leftMax;
        int rightMin, rightMax;
        bool left = isBST(root->left, leftMin, leftMax, leftRes);
        bool right = isBST(root->right, rightMin, rightMax, rightRes);
        if(left && right) {
            if((root->left == NULL || root->val > leftMax) && (root->right == NULL || root->val < rightMin)) {
                curRes = leftRes + rightRes + 1;
                if(root->left != NULL)
                    curMin = leftMin;
                else
                    curMin = root->val;
                if(root->right != NULL)
                    curMax = rightMax;
                else
                    curMax = root->val;
                return true;
            }
        }
        curRes = max(leftRes, rightRes);
        return false;
    }
};
