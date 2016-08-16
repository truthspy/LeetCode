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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = NULL;
        while(fast && fast->next) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = NULL;
        ListNode* p1 = sortList(head);
        ListNode* p2 = sortList(slow);
        ListNode* dummy = new ListNode(0);
        pre = dummy;
        while(p1 && p2) {
            if(p1->val <= p2->val) {
                pre->next = p1;
                p1 = p1->next;
            }
            else {
                pre->next = p2;
                p2 = p2->next;
            }
            pre = pre->next;
        }
        if(p1)
            pre->next = p1;
        else
            pre->next = p2;
        return dummy->next;
    }
};
