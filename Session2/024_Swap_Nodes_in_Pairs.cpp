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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        ListNode* first = head;
        ListNode* second = head->next;
        while(first && first->next) {
            second = first->next;
            pre->next = second;
            first->next = second->next;
            second->next = first;
            pre = first;
            first = first->next;
        }
        return dummy->next;
    }
};
