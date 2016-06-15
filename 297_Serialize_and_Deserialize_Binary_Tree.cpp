/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        if(root == NULL)
            return result;
        ostringstream out;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur == NULL)
                out << "# ";
            else {
                out << cur->val << " "; //需要空格作为分隔符！
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
            return NULL;
        queue<TreeNode*> tree;
        istringstream in(data);         //要记住！！
        string curVal;
        in >> curVal;
        TreeNode *curNode = new TreeNode(stoi(curVal));
        tree.push(curNode);
        while(!tree.empty()) {         //判断条件不能搞错
            TreeNode* root = tree.front();
            tree.pop();
            string left, right;
            in >> left;
            in >> right;
            if(left == "#")
                root->left = NULL;
            else {
                root->left = new TreeNode(stoi(left));
                tree.push(root->left);
            }
            if(right == "#")
                root->right = NULL;
            else {
                root->right = new TreeNode(stoi(right));
                tree.push(root->right);
            }
        }
        return curNode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
