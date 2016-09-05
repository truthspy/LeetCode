/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 双栈实现
// 要注意左右子节点的压栈顺序
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        bool flag = true;
        if(root)
            s1.push(root);
        while(!s1.empty() || !s2.empty()) {
            vector<int> curVec;
            if(flag) {
                while(!s1.empty()) {
                    TreeNode* cur = s1.top();
                    s1.pop();
                    curVec.push_back(cur->val);
                    if(cur->left)
                        s2.push(cur->left);
                    if(cur->right)
                        s2.push(cur->right);
                }
            }
            else {
                while(!s2.empty()) {
                    TreeNode* cur = s2.top();
                    s2.pop();
                    curVec.push_back(cur->val);
                    if(cur->right)
                        s1.push(cur->right);
                    if(cur->left)
                        s1.push(cur->left);
                }
            }
            flag = !flag;
            res.push_back(curVec);
        }
        return res;
    }
};
// 可以不用reverse，知道每层的size之后可以计算出该点的index，直接存入数组中
// 或者用deque
/*
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root != NULL)
            q.push(root);
        bool flag = true;
        while(!q.empty()) {
            int size = q.size();
            TreeNode* cur;
            vector<int> curVec;
            for(int i = 0; i < size; i ++) {
                cur = q.front();
                q.pop();
                curVec.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            if(!flag)
                reverse(curVec.begin(), curVec.end());
            res.push_back(curVec);
            flag = !flag;
        }
        return res;
    }
};*/
