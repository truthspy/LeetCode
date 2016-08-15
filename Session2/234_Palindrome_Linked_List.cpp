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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = NULL;
        while(fast && fast->next) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = NULL;
        ListNode* p1 = head;
        ListNode* p2 = NULL;
        if(fast)
            p2 = slow->next;
        else
            p2 = slow;
        p2 = reverse(p2);
        while(p1 && p2) {
            if(p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return (!p1 && !p2);
    }
    ListNode* reverse(ListNode* head) {
        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *next = NULL;
        while(cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
