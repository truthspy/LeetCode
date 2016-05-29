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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n)
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        while(m > 1) {
            pre = pre->next;
            n --;
            m --;
        }
        ListNode *front = pre->next;
        ListNode *cur = front;
        ListNode *then = cur->next;
        ListNode *end;
        while(n > 1) {
            n --;
            end = then->next;
            then->next = cur;
            cur = then;
            then = end;
        }
        pre->next = cur;
        front->next = end;
        return dummy->next;
    }
};
