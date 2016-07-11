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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        vector<int> curResult;
        getPath(root, sum, result, curResult);
        return result;
    }
    void getPath(TreeNode* root, int sum, vector<vector<int>>& result, vector<int> curResult) {
        if(root->left == NULL && root->right == NULL) {
            if(sum == root->val) {
                curResult.push_back(root->val);
                result.push_back(curResult);
            }
            return;
        }
        curResult.push_back(root->val);
        if(root->left != NULL)
            getPath(root->left, sum - root->val, result, curResult);
        if(root->right != NULL)
            getPath(root->right, sum - root->val, result, curResult);
        // curResult.pop_back();
    }
};
