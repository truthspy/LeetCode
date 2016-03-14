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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        ListNode* first = head;
        int i = 0;
        while(first != NULL) {
            i ++;
            first = first->next;
        }
        k = k % i;
        if(k == 0)
            return head;
        first = head;
        while(k > 0 && first->next != NULL) {
            first = first->next;
            k --;
        }
        ListNode* second = head;
        while(first->next != NULL) {
            first = first->next;
            second = second->next;
        }
        first->next = head;
        head = second->next;
        second->next = NULL;
        return head;
    }
};

 /**已经计算出了长度
  * 所以可以连成一个环
  * 找到len-k的位置即可
  */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        ListNode* first = head;
        int i = 1;
        while(first->next != NULL) {
            i ++;
            first = first->next;
        }
        k = k % i;
        if(k == 0)
            return head;
        first->next = head;
        k = i - k;
        first = head;
        while(k > 1) {
            first = first->next;
            k --;
        }
        head = first->next;
        first->next = NULL;
        return head;
    }
};
