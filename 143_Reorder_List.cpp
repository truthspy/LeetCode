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
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre;
        while(fast && fast->next) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = NULL;
        slow = reverse(slow);
        merge(head, slow);
    }
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* cur = NULL;       //注意！！！要从头指针的前一个开始，不然会形成环！！！
        ListNode* then = head;
        ListNode* tmp;
        while(then) {
            tmp = then->next;
            then->next = cur;
            cur = then;
            then = tmp;
        }
        return cur;
    }
    void merge(ListNode* h1, ListNode* h2) {
        ListNode* then1;
        ListNode* then2;
        while(h1 && h2) {
            then1 = h1->next;
            then2 = h2->next;
            h1->next = h2;
            if(then1)
                h2->next = then1;
            h1 = then1;
            h2 = then2;
        }
    }
};
