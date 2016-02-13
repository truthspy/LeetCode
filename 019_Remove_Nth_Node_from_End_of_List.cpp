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
        if(n == 0)
            return head;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *pre = NULL;
        while(n > 0) {
            n --;
            fast = fast->next;
        }
        while(fast != NULL){
            fast = fast->next;
            pre = slow;
            slow = slow->next;
        }
        if(slow == head)
            return head->next;
        pre->next = slow->next;
        return head;
    }
};
