/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /**
  * 双栈实现
  */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        bool flag = true;
        s1.push(root);
        while(!s1.empty() || !s2.empty()) {
            vector<int> level;
            if(flag) {
                while(!s1.empty()) {
                    TreeNode* tmp = s1.top();
                    s1.pop();
                    level.push_back(tmp->val);
                    if(tmp->left != NULL)
                        s2.push(tmp->left);
                    if(tmp->right != NULL)
                        s2.push(tmp->right);
                }
                result.push_back(level);
                flag = false;
            }
            else {
                while(!s2.empty()) {
                    TreeNode* tmp = s2.top();
                    s2.pop();
                    level.push_back(tmp->val);
                    if(tmp->right != NULL)
                        s1.push(tmp->right);
                    if(tmp->left != NULL)
                        s1.push(tmp->left);
                }
                result.push_back(level);
                flag = true;;
            }
        }
        return result;
    }
};
