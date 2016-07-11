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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int carry = 0;
        while(l1 != NULL && l2 != NULL) {
            int total = l1->val + l2->val + carry;
            carry = total / 10;
            total = total % 10;
            cur->next = new ListNode(total);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL) {
            int total = l1->val + carry;
            carry = total / 10;
            total = total % 10;
            cur->next = new ListNode(total);
            cur = cur->next;
            l1 = l1->next;
        }
        while(l2 != NULL) {
            int total = l2->val + carry;
            carry = total / 10;
            total = total % 10;
            cur->next = new ListNode(total);
            cur = cur->next;
            l2 = l2->next;
        }
        if(carry == 1) {
            cur->next = new ListNode(carry);
            cur = cur->next;
        }
        cur->next = NULL;
        return dummy->next;
    }
};
