/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* nextNode = node->next;
    node->next = nextNode->next;
    node->val = nextNode->val;
    
}
