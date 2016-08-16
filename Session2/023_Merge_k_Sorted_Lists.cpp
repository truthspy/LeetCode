/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        ListNode* dummy = new ListNode(0);
        for(int i = 0; i < lists.size(); i ++) {
            if(lists[i])
                pq.push(lists[i]);
        }
        ListNode* pre = dummy;
        while(!pq.empty()) {
            ListNode* cur = pq.top();
            pq.pop();
            pre->next = cur;
            if(cur->next)
                pq.push(cur->next);
            pre = pre->next;
        }
        pre->next = NULL;
        return dummy->next;
    }
};
