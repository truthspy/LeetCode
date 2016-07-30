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
    int closestValue(TreeNode* root, double target) {
        if((double)root->val == target)
            return root->val;
        if(root->val > target) {
            double diffCur = (double)root->val - target;
            if(!root->left) {
                return root->val;
            }
            int valChild = closestValue(root->left, target);
            double diffChild = abs((double)valChild - target);
            if(diffCur > diffChild)
                return valChild;
            else
                return root->val;
        }
        else {
            double diffCur = target - (double)root->val;
            if(!root->right) {
                return root->val;
            }
            int valChild = closestValue(root->right, target);
            double diffChild = abs((double)valChild - target);
            if(diffCur > diffChild)
                return valChild;
            else
                return root->val;
        }
    }
};
