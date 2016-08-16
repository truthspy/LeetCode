/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
        RandomListNode* cur = head;
        RandomListNode* next = NULL;
        while(cur) {
            RandomListNode* copy = new RandomListNode(cur->label);
            next = cur->next;
            cur->next = copy;
            copy->next = next;
            cur = next;
        }
        cur = head;
        while(cur) {
            // random可能有空的情况，要判断一下，不然random->next会出错
            if(cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        // 要保证原来的链表不能变
        cur = head;
        RandomListNode* copyHead = head->next;
        RandomListNode* copyNode = copyHead;
        while(cur) {
            cur->next = copyNode->next;
            cur = cur->next;
            if(cur) {
                copyNode->next = cur->next;
                copyNode = copyNode->next;
            }
        }
        return copyHead;
    }
};
