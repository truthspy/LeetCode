/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 死活想不出来怎么搞
// 把节点的值改成下一个的值，然后删除下一个。。
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* next = node->next;
        node->next = next->next;
        node->val = next->val;
    }
};
