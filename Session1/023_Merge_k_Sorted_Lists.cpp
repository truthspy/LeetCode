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
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(int i = 0; i < lists.size(); i ++) {
            if(lists[i] != NULL)
                q.push(lists[i]);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;
        while(!q.empty()) {
            ListNode* tmp = q.top();
            q.pop();
            node->next = tmp;
            if(tmp->next != NULL)
                q.push(tmp->next);
            node = node->next;
        }
        return dummy->next;
    }
};

//还可以链表两两合并来完成
