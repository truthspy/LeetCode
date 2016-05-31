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
 * TODO
 * DP方法
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if(n == 0)
            return result;
        return dfs(1, n);
    }
    vector<TreeNode*> dfs(int l, int r) {
        vector<TreeNode*> res;
        if(l > r)
            res.push_back(NULL);
        for(int i = l; i <= r; i ++) {
            // TreeNode* node = new TreeNode(i);        在这里新建node不对，这样会使得res中的所有node都为同一个点
            vector<TreeNode*> res1 = dfs(l, i - 1);
            vector<TreeNode*> res2 = dfs(i + 1, r);
            int size1 = res1.size();
            int size2 = res2.size();
            for(int j = 0; j < size1; j ++) {
                for(int k = 0; k < size2; k ++) {
                    TreeNode* node = new TreeNode(i);
                    node->left = res1[j];
                    node->right = res2[k];
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};
