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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        if(root != NULL)
            q.push(make_pair(root, 0));
        while(!q.empty()) {
            TreeNode* curNode = q.front().first;
            int curPos = q.front().second;
            q.pop();
            mp[curPos].push_back(curNode->val);
            if(curNode->left)
                q.push(make_pair(curNode->left, curPos- 1));
            if(curNode->right)
                q.push(make_pair(curNode->right, curPos + 1));
        }
        vector<vector<int>> res;
        for(auto level : mp)
            res.push_back(level.second);
        return res;
    }
};
