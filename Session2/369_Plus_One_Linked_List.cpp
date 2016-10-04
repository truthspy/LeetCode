/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Method1: 先反转链表，加1，再翻转回去
// Method2: 递归
// Method3: 用栈实现递归
// Method4: 先找到从右边起第一个不为9的数，加1，再把后面的元素都归0
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        stack<ListNode*> nodeStack;
        ListNode* cur = head;
        while(cur) {
            nodeStack.push(cur);
            cur = cur->next;
        }
        int carry = 1;
        while(!nodeStack.empty()) {
            cur = nodeStack.top();
            nodeStack.pop();
            cur->val += carry;
            carry = cur->val / 10;
            cur->val = cur->val % 10;
        }
        if(carry == 1) {
            ListNode* first = new ListNode(1);
            first->next = head;
            head = first;
        }
        return head;
    }
};
