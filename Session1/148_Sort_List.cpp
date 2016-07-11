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
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre;
        while(fast != NULL && fast->next != NULL) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        ListNode* head1 = sortList(head);
        ListNode* head2 = sortList(slow);
        return mergeSortedList(head1, head2);
    }
    ListNode* mergeSortedList(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        while(head1 != NULL && head2 != NULL) {
            if(head1->val <= head2->val) {
                pre->next = head1;
                head1 = head1->next;
            }
            else {
                pre->next = head2;
                head2 = head2->next;
            }
            pre = pre->next;
        }
        if(head1 != NULL)
            pre->next = head1;
        else
            pre->next = head2;
        return dummy->next;
    }
};
