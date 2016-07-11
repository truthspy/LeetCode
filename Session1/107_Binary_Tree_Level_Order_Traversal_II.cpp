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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> results;
        if(root == NULL)
            return results;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()) {
            int size = Q.size();
            vector<int> level;
            for(int i = 0; i < size; i ++) {
                TreeNode* curNode = Q.front();
                level.push_back(curNode->val);
                Q.pop();
                if(curNode->left != NULL)
                    Q.push(curNode->left);
                if(curNode->right != NULL)
                    Q.push(curNode->right);
            }
            results.push_back(level);
        }
        reverse(results.begin(), results.end());
        return results;
    }
};
