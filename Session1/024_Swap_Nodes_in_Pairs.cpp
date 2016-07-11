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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* first = head;
        head = first->next;
        ListNode* pre = NULL;
        while(first != NULL && first->next != NULL) {
            ListNode* second = first->next;
            first->next = second->next;
            //如果一开始在head前增加dummy node，可以减少此判断！！！！
            if(pre != NULL)
                pre->next = second;
            second->next = first;
            pre = first;
            first = first->next;
        }
        return head;
    }
};
