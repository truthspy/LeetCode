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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while(n > 0) {
            fast = fast->next;
            n --;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        while(fast) {
            fast = fast->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = slow->next;
        return dummy->next;
    }
};
