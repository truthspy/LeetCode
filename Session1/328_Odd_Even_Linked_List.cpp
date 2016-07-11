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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        ListNode *oddHead = head;
        ListNode *evenHead = head->next;
        ListNode *odd = oddHead;
        ListNode *even = evenHead;
        while(true) {
            if(even->next != NULL) {
                odd->next = even->next;
                odd = odd->next;
            }
            else
                break;
            if(odd->next != NULL) {
                even->next = odd->next;
                even = even->next;
            }
            else
                break;
        }
        even->next = NULL;
        odd->next = evenHead;
        return oddHead;
    }
};
