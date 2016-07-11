/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
/**TODO
 * O(1)空间复杂度的解法
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
        RandomListNode* copyHead = new RandomListNode(head->label);
        unordered_map<RandomListNode*, RandomListNode*> hashTable;
        hashTable[head] = copyHead;
        RandomListNode* cur = head->next;
        RandomListNode* copyCur;
        RandomListNode* copyPre = copyHead;
        while(cur != NULL) {
            copyCur = new RandomListNode(cur->label);
            hashTable[cur] = copyCur;
            copyPre->next = copyCur;
            copyPre= copyCur;
            cur = cur->next;
        }
        cur = head;
        copyCur = copyHead;
        while(cur != NULL) {
            if(cur->random != NULL)
                copyCur->random = hashTable[cur->random];
            cur = cur->next;
            copyCur = copyCur->next;
        }
        return copyHead;
    }
};
