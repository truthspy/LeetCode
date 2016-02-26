/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        /* 
        while循环中还会判断，可以省去root->left == NULL
        if(root == NULL || root->left == NULL)
            return;
        */
        if(root == NULL)
            return;
        TreeLinkNode *node = root;
        /*
        所有next初始化为NULL，所以不用考虑最右边节点的情况
        root->next = NULL;
        */
        while(node->left != NULL) {
            TreeLinkNode *tmp = node->left;
            while(node != NULL) {
                node->left->next = node->right;
                /*
                所有next初始化为NULL，所以不用考虑最右边节点的情况
                if(node->next == NULL)
                    node->right->next = NULL;
                else
                    node->right->next = node->next->left;
                */
                if(node->next != NULL)
                    node->right->next = node->next->left;
                node = node->next;
            }
            node = tmp;
        }
    }
};
