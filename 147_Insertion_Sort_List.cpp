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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = NULL;
        ListNode *cur = head;
        ListNode *next;
        while(cur != NULL) {
            next = cur->next;
            ListNode* nextSort = dummy;
            while(nextSort->next != NULL && cur->val > nextSort->next->val) {
                nextSort = nextSort->next;
            }
            ListNode* tmp = nextSort->next;
            nextSort->next = cur;
            cur->next = tmp;
            cur = next;
        }
        return dummy->next;
    }
};
