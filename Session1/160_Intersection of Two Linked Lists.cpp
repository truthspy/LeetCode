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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;
        while(pA != NULL && pB!= NULL) {
            pA = pA->next;
            pB = pB->next;
        }
        ListNode *pLong = NULL;
        if(pA == NULL) {
            pA = headA;
            pLong = headB;
            while(pB != NULL) {
                pB = pB->next;
                pLong = pLong->next;
            }
            pB = pLong;
        }
        else{
            pB = headB;
            pLong = headA;
            while(pA != NULL) {
                pA = pA->next;
                pLong = pLong->next;
            }
            pA = pLong;
        }
        while(pA != pB){
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};
