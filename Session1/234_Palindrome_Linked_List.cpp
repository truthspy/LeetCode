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
        ListNode *fast = head;
        ListNode *slow = head;

        while(fast != NULL) {
            if(fast->next == NULL)
                break;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast != NULL)
            slow = slow->next;
        ListNode *pre = NULL;
        ListNode *tmp = NULL;
        while(slow != NULL) {
             tmp = slow->next;
             slow->next = pre;
             pre = slow;
             slow = tmp;
        }
        fast = head;
        while(pre != NULL) {
            if(pre->val != fast->val)
                break;
            pre = pre->next;
            fast = fast->next;
        }
        if(pre == NULL)
            return true;
        else
            return false;
    }
};
