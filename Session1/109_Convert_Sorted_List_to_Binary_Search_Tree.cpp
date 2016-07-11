/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return (new TreeNode(head->val));
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* last = NULL;
        while(fast != NULL && fast->next != NULL) {
            last = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        last->next = NULL;  //要把左半段的尾指针置空！！！
        TreeNode* treenode = new TreeNode(slow->val);
        treenode->right = sortedListToBST(slow->next);
        treenode->left = sortedListToBST(head);
        return treenode;
    }
};
