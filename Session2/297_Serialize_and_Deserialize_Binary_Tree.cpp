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
        string res = "";
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur == NULL)
                res += "#,";
            else {
                res += (to_string(cur->val) + ",");
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        if(data == "")
            return root;
        int pos = data.find(',');
        root = new TreeNode(atoi(data.substr(0, pos).c_str()));
        queue<TreeNode*> q;
        q.push(root);
        data = data.substr(pos + 1);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            int pos1 = data.find(',');
            string left = data.substr(0, pos1);
            data = data.substr(pos1 + 1);
            int pos2 = data.find(',');
            string right = data.substr(0, pos2);
            data = data.substr(pos2 + 1);
            if(left != "#") {
                TreeNode* leftNode = new TreeNode(atoi(left.c_str()));
                cur->left = leftNode;
                q.push(leftNode);
            }
            if(right != "#") {
                TreeNode* rightNode = new TreeNode(atoi(right.c_str()));
                cur->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
