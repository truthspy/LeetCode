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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return NULL;
        return toBST(nums, 0, n - 1);
    }
    TreeNode* toBST(vector<int>& nums, int start, int end) {
        if(start > end)
            return NULL;
        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = toBST(nums, start, mid - 1);
        root->right = toBST(nums, mid + 1, end);
        return root;
    }
};
