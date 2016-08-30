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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> curRes;
        queue<TreeNode*> q;
        if(root == NULL)
            return res;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            while(size > 0) {
                size --;
                TreeNode* cur = q.front();
                q.pop();
                curRes.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            res.push_back(curRes);
            curRes.clear();
        }
        return res;
    }
};
