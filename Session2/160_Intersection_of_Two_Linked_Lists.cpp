/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// more elegent code
// 迫使两个链表形成环
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        if(!p1 || !p2)
            return NULL;
        while(p1 && p2 && p1 != p2) {
            // 有两个同时是null的情况，要放在next之后判断
            // if(p1 == p2)
            //     return p1;
            p1 = p1->next;
            p2 = p2->next;
            if(p1 == p2)
                return p1;
            if(!p1)
                p1 = headB;
            if(!p2)
                p2 = headA;
        }
        return p1;
    }
};
/*
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        while(l1 && l2) {
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* fast = NULL;
        ListNode* slow = NULL;
        if(l1) {
            fast = headA;
            while(l1) {
                fast = fast->next;
                l1 = l1->next;
            }
            slow = headB;
        }
        else {
            fast = headB;
            while(l2) {
                fast = fast->next;
                l2 = l2->next;
            }
            slow = headA;
        }
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
*/
