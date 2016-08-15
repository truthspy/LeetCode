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
        ListNode* pre = dummy;
        int carry = 0;
        while(l1 || l2) {
            if(l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            pre->next = new ListNode(carry % 10);
            carry = carry / 10;
            pre = pre->next;
        }
        if(carry != 0)
            pre->next = new ListNode(carry);
        return dummy->next;
    }
};
