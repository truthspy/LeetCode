/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    while(head != NULL && head->val == val){ 
        head = head->next;
    }
    if(head == NULL)
        return head;
    struct ListNode* currentNode = head;
    struct ListNode* nextNode = currentNode->next;
    while(nextNode != NULL) {
        while(nextNode != NULL && nextNode->val == val) {
            nextNode = nextNode->next;
        }
        currentNode->next = nextNode;
        if(nextNode == NULL)
            break;
        nextNode = nextNode->next;
        currentNode = currentNode->next;
    }
    return head;
}
