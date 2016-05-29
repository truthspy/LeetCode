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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *cur = head;
        while(cur != NULL) {
            if(cur->next == NULL || cur->val != cur->next->val) {
                pre->next = cur;
                pre = cur;
                cur = cur->next;
            }
            else {
                cur = cur->next;
                int val = cur->val;
                while(cur != NULL && cur->val == val)
                    cur = cur->next;
            }
        }
        pre->next = NULL;
        return dummy->next;
    }
};
