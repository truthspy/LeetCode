/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
 思路：
 递归，加helper函数 from discuss
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        
        /*
        to_string函数：将数字转string
        */
        if(root != NULL)
            getPath(root, to_string(root->val), result);
        return result;
    }
    //传result参数的时候要加引用！！因为要保留值
    void getPath(TreeNode *root, string path, vector<string>& result) {
        if(root->left == NULL && root->right == NULL) {
            result.push_back(path);
            return;
        }
        //不是if else，是左右都要！！
        if(root->left != NULL) {
            getPath(root->left, path + "->" + to_string(root->left->val), result);
        }
        if(root->right != NULL){
            getPath(root->right, path + "->" + to_string(root->right->val), result);
        }
    }
};
