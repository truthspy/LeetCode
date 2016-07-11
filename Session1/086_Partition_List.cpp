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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyLess = new ListNode(0);
        ListNode* dummyGreater = new ListNode(0);
        ListNode* curLess = dummyLess;
        ListNode* curGreater = dummyGreater;
        ListNode* cur = head;
        while(cur != NULL) {
            if(cur->val < x) {
                curLess->next = cur;
                curLess = curLess->next;
            }
            else {
                curGreater->next = cur;
                curGreater = curGreater->next;
            }
            cur = cur->next;
        }
        curLess->next = dummyGreater->next;
        curGreater->next = NULL;
        return dummyLess->next;
    }
};
