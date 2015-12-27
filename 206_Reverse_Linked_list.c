/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL)
        return head;
    struct ListNode *lastNode = NULL;
    struct ListNode *currentNode = head;
    struct ListNode *nextNode = NULL;
    while(currentNode->next != NULL) {
        nextNode = currentNode->next;
        currentNode->next = lastNode;
        lastNode = currentNode;
        currentNode = nextNode;
    }
    currentNode->next = lastNode;
    return currentNode;
}
