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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        ListNode *dummy = new ListNode(0);
        if(l1->val <= l2->val) {
            dummy->next = l1;
            l1 = l1->next;
        }
        else {
            dummy->next = l2;
            l2 = l2->next;
        }
        ListNode *currentNode = dummy->next;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                currentNode->next = l1;
                currentNode = l1;
                l1 = l1->next;
            }
            else {
                currentNode->next = l2;
                currentNode = l2;
                l2 = l2->next;
            }
        }
        if(l1 != NULL){
            currentNode->next = l1;
        }
        else {
            currentNode->next = l2;
        }
        return dummy->next;
    }
};
