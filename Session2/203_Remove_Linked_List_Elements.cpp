/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 如果有等于val的，把val前后相连，这样可以比下面的算法减少一些next的赋值操作
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        ListNode* cur = head;
        while(cur) {
            if(cur->val != val) {
                pre->next = cur;
                pre = cur;
            }
            cur = cur->next;
        }
        pre->next = NULL;
        return dummy->next;
    }
};
