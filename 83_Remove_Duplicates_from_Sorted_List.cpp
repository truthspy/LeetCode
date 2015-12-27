/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode *pre = head;
        ListNode *current = head->next;
        while(current != NULL) {
            if(current->val != pre->val){
                pre->next = current;
                pre = pre->next;
            }
            current = current->next;
        }
        pre->next = NULL;
        return head;
    }
};
